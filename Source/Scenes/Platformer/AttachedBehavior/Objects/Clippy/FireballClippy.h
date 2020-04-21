#pragma once
#include <set>

#include "Engine/Hackables/Menus/Clippy.h"

class SmartAnimationNode;

class FireballClippy : public Clippy
{
public:
	static FireballClippy* create();

	void startDialogue() override;

protected:
	FireballClippy();
	virtual ~FireballClippy();

private:
	typedef Clippy super;

	SmartAnimationNode* clippyAnimations;
};