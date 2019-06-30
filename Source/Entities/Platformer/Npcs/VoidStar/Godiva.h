#pragma once
#include <string>

#include "Entities/Platformer/NpcBase.h"

class HexusOpponentData;

class Godiva : public NpcBase
{
public:
	static Godiva* deserialize(cocos2d::ValueMap& initProperties);

	cocos2d::Vec2 getAvatarFrameOffset() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyGodiva;

private:
	typedef NpcBase super;
	Godiva(cocos2d::ValueMap& initProperties);
	~Godiva();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};