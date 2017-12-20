#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "GUI/Components/MenuLabel.h"
#include "GUI/Components/Mouse.h"
#include "GUI/Screens/TitleScreen.h"

using namespace cocos2d;

class StoryMap : public Scene
{
public:
	static StoryMap * create();

protected:
	StoryMap();
	~StoryMap();

private:
	void onEnter() override;
	void InitializeListeners();
	void OnKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

	Mouse* mouse;

	Sprite* background;
	MenuLabel* titleLabel;
	MenuLabel* infoLabel;

	const float titleFontSize = 48.0f;
	const float infoFontSize = 32.0f;
};
