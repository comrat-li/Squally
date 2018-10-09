#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentForestWerewolf : public HexusOpponentData
{
public:
	static HexusOpponentForestWerewolf* getInstance();

private:
	HexusOpponentForestWerewolf();
	~HexusOpponentForestWerewolf();

	static const std::string StringKeyOpponentName;
	static HexusOpponentForestWerewolf* instance;
};