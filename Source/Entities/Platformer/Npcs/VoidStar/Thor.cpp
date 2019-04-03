//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED. ONLY EDIT NON-GENERATED SECTIONS. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Thor.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"

#include "Resources/EntityResources.h"
#include "Resources/HexusResources.h"
#include "Resources/UIResources.h"

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////A////A////A////A////A////A////A////A////A////A/

////B////B////B////B////B////B////B////B////B////B/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

using namespace cocos2d;

const std::string Thor::MapKeyThor = "thor";
HexusOpponentData* Thor::HexusOpponentDataInstance = nullptr;
const std::string Thor::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_THOR";

Thor* Thor::deserialize(ValueMap& initProperties)
{
	Thor* instance = new Thor(initProperties);

	instance->autorelease();

	return instance;
}

Thor::Thor(ValueMap& initProperties) : NpcBase(initProperties,
	EntityResources::Npcs_VoidStar_Thor_Animations,
	EntityResources::Npcs_VoidStar_Thor_Emblem,
	PlatformerCollisionType::FriendlyNpc,
	Size(112.0f, 160.0f),
	1.0f,
	Vec2(0.0f, 0.0f),
	10,
	10)
{
	this->hexusOpponentData = Thor::getHexusOpponentData();

	///////////////////////////////////////////////////
	// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
	////Y////Y////Y////Y////Y////Y////Y////Y////Y////Y/

	////Z////Z////Z////Z////Z////Z////Z////Z////Z////Z/
	// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
	///////////////////////////////////////////////////
}

Thor::~Thor()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

Vec2 Thor::getAvatarFrameOffset()
{
	return Vec2(-32.0f, -112.0f);
}

HexusOpponentData* Thor::getHexusOpponentData()
{
	if (Thor::HexusOpponentDataInstance == nullptr)
	{
		Thor::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Npcs_VoidStar_Thor_Animations,
			HexusResources::Menus_HexusFrameVoidStar,
			1.0f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			Thor::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			0.906f,
			HexusOpponentData::generateDeck(25, 0.906f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Absorb),
				CardList::getInstance()->cardListByName.at(CardKeys::Subtraction),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				CardList::getInstance()->cardListByName.at(CardKeys::SuddenDeath),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip3),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::Subtraction),
				CardList::getInstance()->cardListByName.at(CardKeys::BonusMoves),
				CardList::getInstance()->cardListByName.at(CardKeys::Drank),

			}),
			nullptr
		);
	}

	return Thor::HexusOpponentDataInstance;
}