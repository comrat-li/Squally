#pragma once

#include "Scenes/Platformer/Level/Combat/Buffs/Buff.h"

namespace cocos2d
{
	class Sprite;
}

class HackablePreview;
class PlatformerEntity;
class SmartParticles;
class WorldSound;

class Enrage : public Buff
{
public:
	static Enrage* create(PlatformerEntity* caster, PlatformerEntity* target);

	static const std::string PropertyRestorePotionTutorial;
	static const std::string EnrageIdentifier;

protected:
	Enrage(PlatformerEntity* caster, PlatformerEntity* target);
	virtual ~Enrage();

	void onEnter() override;
	void initializePositions() override;
	void registerHackables() override;
	void onModifyTimelineSpeed(float* timelineSpeed, std::function<void()> handleCallback) override;
	void onBeforeDamageTaken(volatile int* damageOrHealing, std::function<void()> handleCallback, PlatformerEntity* caster, PlatformerEntity* target) override;
	void onBeforeDamageDelt(volatile int* damageOrHealing, std::function<void()> handleCallback, PlatformerEntity* caster, PlatformerEntity* target) override;

private:
	typedef Buff super;

	void applyEnrageSpeed();
	void applyEnrageIncreaseDamageDelt();
	void applyEnrageIncreaseDamageTaken();
	
	volatile float currentSpeed;
	
	SmartParticles* spellEffect;
	cocos2d::Sprite* spellAura;

	static const float MinSpeed;
	static const float DefaultSpeed;
	static const float MaxSpeed;
	static const float Duration;
};
