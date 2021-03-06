#include "Laser.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationSequenceNode.h"
#include "Engine/Hackables/HackableCode.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Utils/GameUtils.h"
#include "Objects/Platformer/Traps/Laser/LaserAnimation.h"
#include "Objects/Platformer/Traps/Laser/LaserCountDownPreview.h"
#include "Objects/Platformer/Traps/Laser/LaserGenericPreview.h"
#include "Scenes/Platformer/Hackables/HackFlags.h"
#include "Scenes/Platformer/Level/Physics/PlatformerCollisionType.h"

#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

#define LOCAL_FUNC_ID_INCREMENT_ANIMATION_FRAME 1

const std::string Laser::MapKey = "laser";

Laser* Laser::create(ValueMap& properties)
{
	Laser* instance = new Laser(properties);

	instance->autorelease();

	return instance;
}

Laser::Laser(ValueMap& properties) : super(properties)
{
	this->currentLaserCountDown = RandomHelper::random_real(0.0f, 3.0f);
	this->maxLaserCountDown = 4.0f;
	this->isRunningAnimation = false;

	float height = this->properties.at(GameObject::MapKeyHeight).asFloat();

	this->laserAnimation = LaserAnimation::create(height);
	this->laserCollision = CollisionObject::create(CollisionObject::createBox(Size(21.0f, height)), (CollisionType)PlatformerCollisionType::Damage, CollisionObject::Properties(false, false));

	this->addChild(this->laserCollision);
	this->addChild(this->laserAnimation);
}

Laser::~Laser()
{
}

void Laser::onEnter()
{
	super::onEnter();

	this->scheduleUpdate();
}

void Laser::update(float dt)
{
	super::update(dt);

	this->updateLaser(dt);
}

void Laser::initializePositions()
{
	super::initializePositions();

	this->laserCollision->setPosition(Vec2::ZERO);
}

Vec2 Laser::getButtonOffset()
{
	return Vec2(0.0f, 0.0f);
}

void Laser::registerHackables()
{
	super::registerHackables();
	
	HackableCode::CodeInfoMap codeInfoMap =
	{
		{
			LOCAL_FUNC_ID_INCREMENT_ANIMATION_FRAME,
			HackableCode::HackableCodeInfo(
				Laser::MapKey,
				Strings::Menus_Hacking_Objects_Laser_UpdateCountDown_UpdateCountDown::create(),
				HackableBase::HackBarColor::Red,
				UIResources::Menus_Icons_SpellImpactWhite,
				LaserCountDownPreview::create(),
				{
					{ HackableCode::Register::zbx, Strings::Menus_Hacking_Objects_Laser_UpdateCountDown_RegisterSt0::create() },
				},
				int(HackFlags::Fire),
				20.0f,
				0.0f
			)
		},
	};

	auto updateLaserFunc = &Laser::updateLaser;
	std::vector<HackableCode*> hackables = HackableCode::create((void*&)updateLaserFunc, codeInfoMap);

	for (auto next : hackables)
	{
		this->registerCode(next);
	}
}

HackablePreview* Laser::createDefaultPreview()
{
	return LaserGenericPreview::create();
}

NO_OPTIMIZE void Laser::updateLaser(float dt)
{
	if (this->isRunningAnimation)
	{
		return;
	}

	static volatile float* countDownPtr;
	static volatile float* deltaTimePtr;

	countDownPtr = &this->currentLaserCountDown;
	deltaTimePtr = &dt;

	ASM(push ZAX);
	ASM(push ZBX);
	ASM_MOV_REG_VAR(ZAX, countDownPtr);
	ASM_MOV_REG_VAR(ZBX, deltaTimePtr);

	ASM(fld dword ptr [ZAX]);

	HACKABLE_CODE_BEGIN(LOCAL_FUNC_ID_INCREMENT_ANIMATION_FRAME);
	ASM(fsub dword ptr [ZBX]);
	ASM_NOP12();
	HACKABLE_CODE_END();

	ASM(fstp dword ptr [ZAX])

	ASM(pop ZAX);
	ASM(pop ZBX);

	HACKABLES_STOP_SEARCH();

	if (this->currentLaserCountDown <= 0.0f)
	{
		const float stayActiveDuration = 1.5f;

		this->isRunningAnimation = true;
		this->currentLaserCountDown = this->maxLaserCountDown - RandomHelper::random_real(0.0f, 0.5f);

		this->laserAnimation->runAnimation(
		[=]()
		{
			this->laserCollision->setPhysicsEnabled(true);
		},
		[=]()
		{
			this->laserCollision->setPhysicsEnabled(false);
			this->isRunningAnimation = false;
		});
	}
}
END_NO_OPTIMIZE
