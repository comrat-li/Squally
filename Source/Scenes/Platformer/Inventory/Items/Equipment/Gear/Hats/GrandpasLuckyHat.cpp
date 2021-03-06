#include "GrandpasLuckyHat.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string GrandpasLuckyHat::SaveKey = "grandpas-lucky-hat";

GrandpasLuckyHat* GrandpasLuckyHat::create()
{
	GrandpasLuckyHat* instance = new GrandpasLuckyHat();

	instance->autorelease();

	return instance;
}

GrandpasLuckyHat::GrandpasLuckyHat() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), ItemStats(
	// Health
	0,
	// Mana
	0,
	// Attack
	0,
	// Armor
	0,
	// Speed
	0.05f
))
{
}

GrandpasLuckyHat::~GrandpasLuckyHat()
{
}

Item* GrandpasLuckyHat::clone()
{
	return GrandpasLuckyHat::create();
}

std::string GrandpasLuckyHat::getItemName()
{
	return GrandpasLuckyHat::SaveKey;
}

LocalizedString* GrandpasLuckyHat::getString()
{
	return Strings::Items_Equipment_Gear_Hats_GrandpasLuckyHat::create();
}

std::string GrandpasLuckyHat::getIconResource()
{
	return ItemResources::Equipment_Gear_Hats_GrandpasLuckyHat;
}

std::string GrandpasLuckyHat::getSerializationKey()
{
	return GrandpasLuckyHat::SaveKey;
}

Vec2 GrandpasLuckyHat::getDisplayOffset()
{
	return Vec2(6.0f, -26.0f);
}
