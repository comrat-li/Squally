#include "Warp.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCValue.h"

#include "Engine/Camera/GameCamera.h"
#include "Engine/Events/NavigationEvents.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Maps/MapLayer.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Utils/GameUtils.h"
#include "Engine/Utils/StrUtils.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/PlatformerEvents.h"
#include "Objects/Platformer/Interactables/Doors/Portal.h"
#include "Scenes/Platformer/Level/PlatformerMap.h"
#include "Scenes/Platformer/Level/Physics/PlatformerCollisionType.h"

#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string Warp::MapKey = "warp";
const std::string Warp::PropertyWarpFrom = "from";
const std::string Warp::PropertyWarpTo = "to";
const std::string Warp::PropertyZoom = "zoom";
const std::string Warp::PropertyNoWarpCamera = "no-warp-camera";
const std::string Warp::PropertyRelayer = "relayer";
const std::string Warp::EventWarpToPrefix = "EVENT_WARP_TO_";

Warp* Warp::create(ValueMap& properties)
{
	Warp* instance = new Warp(properties);

	instance->autorelease();

	return instance;
}

Warp::Warp(ValueMap& properties) : super(properties, Size(properties.at(GameObject::MapKeyWidth).asFloat(), properties.at(GameObject::MapKeyHeight).asFloat()))
{
	this->from = GameUtils::getKeyOrDefault(this->properties, Warp::PropertyWarpFrom, Value("")).asString();
	this->to = GameUtils::getKeyOrDefault(this->properties, Warp::PropertyWarpTo, Value("")).asString();
	this->warpCamera = !GameUtils::getKeyOrDefault(this->properties, Warp::PropertyNoWarpCamera, Value(false)).asBool();
	this->relayer = GameUtils::getKeyOrDefault(this->properties, Warp::PropertyRelayer, Value(false)).asBool();
	this->zoomOverride = GameUtils::getKeyOrDefault(this->properties, Warp::PropertyZoom, Value(0.0f)).asFloat();

	this->setName("Warp from " + this->from + " to " + this->to);
	this->setInteractType(InteractType::Input);
}

Warp::~Warp()
{
}

void Warp::onEnter()
{
	super::onEnter();
}

void Warp::initializePositions()
{
	super::initializePositions();
}

void Warp::initializeListeners()
{
	super::initializeListeners();

	this->listenForMapEvent(Warp::EventWarpToPrefix + this->from, [=](ValueMap args)
	{
		ObjectEvents::QueryObjects(QueryObjectsArgs<Squally>([=](Squally* squally)
		{
			this->doRelayer();
			this->applyZoomOverride();

			PlatformerEvents::TriggerWarpObjectToLocation(PlatformerEvents::WarpObjectToLocationArgs(squally, GameUtils::getWorldCoords3D(this), this->warpCamera));
		}), Squally::MapKey);
	});
}

void Warp::loadMap()
{
	this->broadcastMapEvent(Warp::EventWarpToPrefix + this->to, ValueMap());
}

void Warp::doRelayer()
{
	if (!this->relayer)
	{
		return;
	}

	MapLayer* layer = GameUtils::getFirstParentOfType<MapLayer>(this);

	if (layer != nullptr)
	{
		GameUtils::changeParent(squally, layer, true);
	}
}

void Warp::applyZoomOverride()
{
	if (this->zoomOverride == 0.0f)
	{
		return;
	}

	CameraTrackingData* data = GameCamera::getInstance()->getCurrentTrackingData();

	if (data != nullptr)
	{
		data->zoom = this->zoomOverride;
	}
}
