#include "SteelSword.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string SteelSword::SaveKey = "steel-sword";

SteelSword* SteelSword::create()
{
	SteelSword* instance = new SteelSword();

	instance->autorelease();

	return instance;
}

SteelSword::SteelSword() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 6 }}), 6, 8, ItemStats(
	// Health
	0,
	// Mana
	0,
	// Attack
	0,
	// Armor
	0,
	// Speed
	0.15f
))
{
}

SteelSword::~SteelSword()
{
}

Item* SteelSword::clone()
{
	return SteelSword::create();
}

std::string SteelSword::getItemName()
{
	return SteelSword::SaveKey;
}

LocalizedString* SteelSword::getString()
{
	return Strings::Items_Equipment_Weapons_Swords_SteelSword::create();
}

std::string SteelSword::getIconResource()
{
	return ItemResources::Equipment_Weapons_Swords_SteelSword;
}

std::string SteelSword::getSerializationKey()
{
	return SteelSword::SaveKey;
}
