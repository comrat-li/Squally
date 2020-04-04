#pragma once
#include <set>

#include "Engine/Hackables/Clippy.h"

class SmartAnimationNode;
class Sound;

class StrengthClippy : public Clippy
{
public:
	static StrengthClippy* create();

	void startDialogue() override;

protected:
	StrengthClippy();
	virtual ~StrengthClippy();

	Clippy* innerClone() override;

private:
	typedef Clippy super;

	SmartAnimationNode* clippyAnimations;
};