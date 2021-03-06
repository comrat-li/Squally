#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class Squally;

class SquallyEqBehavior : public AttachedBehavior
{
public:
	static SquallyEqBehavior* create(GameObject* owner);

	static const std::string MapKey;

protected:
	SquallyEqBehavior(GameObject* owner);
	virtual ~SquallyEqBehavior();

	void onLoad() override;
	void onDisable() override;

private:
	typedef AttachedBehavior super;

	Squally* squally;
};
