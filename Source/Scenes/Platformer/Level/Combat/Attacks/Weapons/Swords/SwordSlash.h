#pragma once

#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttack.h"

class WorldSound;

class SwordSlash : public PlatformerAttack
{
public:
	static SwordSlash* create(int damageMin, int damageMax, float attackDuration, float recoverDuration, float priority);

	LocalizedString* getString() override;
	std::string getAttackAnimation() override;
	void onAttackTelegraphBegin() override;

protected:
	SwordSlash(int damageMin, int damageMax, float attackDuration, float recoverDuration, float priority);
	virtual ~SwordSlash();

	void performAttack(PlatformerEntity* owner, PlatformerEntity* target) override;
	void doDamageOrHealing(PlatformerEntity* owner, PlatformerEntity* target) override;

private:
	typedef PlatformerAttack super;
	
	PlatformerAttack* cloneInternal() override;

	WorldSound* SwordSlashSound;
	WorldSound* hitSound;
};
