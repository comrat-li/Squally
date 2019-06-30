#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;

class Gargoyle : public PlatformerEnemy
{
public:
	static Gargoyle* deserialize(cocos2d::ValueMap& initProperties);

	cocos2d::Vec2 getAvatarFrameOffset() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyGargoyle;

private:
	typedef PlatformerEnemy super;
	Gargoyle(cocos2d::ValueMap& initProperties);
	~Gargoyle();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};