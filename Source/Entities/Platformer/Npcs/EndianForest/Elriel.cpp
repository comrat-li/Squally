//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED. ONLY EDIT NON-GENERATED SECTIONS. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Elriel.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/EntityResources.h"
#include "Resources/HexusResources.h"
#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string Elriel::MapKeyElriel = "elriel";
HexusOpponentData* Elriel::HexusOpponentDataInstance = nullptr;
const std::string Elriel::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_ELRIEL";

Elriel* Elriel::deserialize(ValueMap& initProperties)
{
	Elriel* instance = new Elriel(initProperties);

	instance->autorelease();

	return instance;
}

Elriel::Elriel(ValueMap& initProperties) : NpcBase(initProperties,
	EntityResources::Npcs_EndianForest_Elriel_Animations,
	EntityResources::Npcs_EndianForest_Elriel_Emblem,
	PlatformerCollisionType::FriendlyNpc,
	Size(112.0f, 160.0f),
	1.0f,
	Vec2(0.0f, 0.0f),
	16,
	8)
{
	this->hexusOpponentData = Elriel::getHexusOpponentData();
}

Elriel::~Elriel()
{
}

Vec2 Elriel::getAvatarFrameOffset()
{
	return Vec2(-32.0f, -112.0f);
}

HexusOpponentData* Elriel::getHexusOpponentData()
{
	if (Elriel::HexusOpponentDataInstance == nullptr)
	{
		Elriel::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Npcs_EndianForest_Elriel_Animations,
			HexusResources::Menus_HexusFrameEndianForest,
			1.0f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			Elriel::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Earth,
			0.096f,
			HexusOpponentData::generateDeck(32, 0.096f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip1),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalAnd),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),

			}),
			nullptr
		);
	}

	return Elriel::HexusOpponentDataInstance;
}