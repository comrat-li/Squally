#include "DemonicSword.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string DemonicSword::SaveKey = "demonic-sword";

DemonicSword* DemonicSword::create()
{
	DemonicSword* instance = new DemonicSword();

	instance->autorelease();

	return instance;
}

DemonicSword::DemonicSword() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), 11, 15, ItemStats(
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

DemonicSword::~DemonicSword()
{
}

Item* DemonicSword::clone()
{
	return DemonicSword::create();
}

std::string DemonicSword::getItemName()
{
	return DemonicSword::SaveKey;
}

LocalizedString* DemonicSword::getString()
{
	return Strings::Items_Equipment_Weapons_Swords_DemonicSword::create();
}

std::string DemonicSword::getIconResource()
{
	return ItemResources::Equipment_Weapons_Swords_DemonicSword;
}

std::string DemonicSword::getSerializationKey()
{
	return DemonicSword::SaveKey;
}
