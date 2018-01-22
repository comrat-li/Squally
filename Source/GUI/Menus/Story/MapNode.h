#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "GUI/Components/Mouse.h"
#include "Level/Level.h"
#include "Utils/Utils.h"

using namespace cocos2d;

class MapNode : public Node
{
public:
	static MapNode * create(std::string mapName, std::string mapFile, Vec2 position);

	void setCallBack(std::function<void(MapNode*)> onMouseOver);

	std::string nodeMapName;
	std::string nodeMapFile;

protected:
	MapNode(std::string mapName, std::string mapFile, Vec2 position);
	~MapNode();

private:
	void initializeListeners();
	void onMouseMove(EventMouse* event);
	void onMouseDown(EventMouse* event);

	std::function<void(MapNode*)> onMouseOverEvent;

	Mouse* mouse;
	Sprite* sprite;
	Sprite* spriteLocked;
	Sprite* spriteSelected;
};
