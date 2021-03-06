#include "CrystalBow.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string CrystalBow::SaveKey = "crystal-bow";

CrystalBow* CrystalBow::create()
{
	CrystalBow* instance = new CrystalBow();

	instance->autorelease();

	return instance;
}

CrystalBow::CrystalBow() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), 32, 40, ItemStats(
	// Health
	0,
	// Mana
	0,
	// Attack
	0,
	// Armor
	0,
	// Speed
	0.25f
))
{
}

CrystalBow::~CrystalBow()
{
}

Item* CrystalBow::clone()
{
	return CrystalBow::create();
}

std::string CrystalBow::getItemName()
{
	return CrystalBow::SaveKey;
}

LocalizedString* CrystalBow::getString()
{
	return Strings::Items_Equipment_Weapons_Bows_CrystalBow::create();
}

std::string CrystalBow::getIconResource()
{
	return ItemResources::Equipment_Weapons_Bows_CrystalBow;
}

std::string CrystalBow::getSerializationKey()
{
	return CrystalBow::SaveKey;
}

Vec2 CrystalBow::getDisplayOffset()
{
	return Vec2(-10.0f, -74.0f);
}
