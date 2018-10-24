#include "HexusOpponentBlackbeard.h"

const std::string HexusOpponentBlackbeard::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_BLACKBEARD";
HexusOpponentBlackbeard* HexusOpponentBlackbeard::instance = nullptr;

HexusOpponentBlackbeard* HexusOpponentBlackbeard::getInstance()
{
	if (HexusOpponentBlackbeard::instance == nullptr)
	{
		HexusOpponentBlackbeard::instance = new HexusOpponentBlackbeard();
	}

	return HexusOpponentBlackbeard::instance;
}

HexusOpponentBlackbeard::HexusOpponentBlackbeard() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Jungle_Npcs_Blackbeard_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameJungle,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -64.0f),
	HexusOpponentBlackbeard::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	HexusOpponentData::generateReward(0.1f),
	HexusOpponentData::generateDeck(25, 0.1f,
		{
			CardList::getInstance()->cardListByName->at(CardKeys::Binary0),
			CardList::getInstance()->cardListByName->at(CardKeys::Hex0),
			CardList::getInstance()->cardListByName->at(CardKeys::Decimal0),
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		})
	)
{
}

HexusOpponentBlackbeard::~HexusOpponentBlackbeard()
{
}