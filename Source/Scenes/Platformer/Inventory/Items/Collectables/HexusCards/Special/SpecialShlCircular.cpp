#include "SpecialShlCircular.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Hexus/CardData/CardKeys.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string SpecialShlCircular::SaveKey = "special-shl-circular";

SpecialShlCircular* SpecialShlCircular::create()
{
	SpecialShlCircular* instance = new SpecialShlCircular();

	instance->autorelease();

	return instance;
}

SpecialShlCircular::SpecialShlCircular() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 7 }}), ItemMeta(3, 3))
{
}

SpecialShlCircular::~SpecialShlCircular()
{
}

Item* SpecialShlCircular::clone()
{
	return SpecialShlCircular::create();
}

std::string SpecialShlCircular::getItemName()
{
	return SpecialShlCircular::SaveKey;
}

LocalizedString* SpecialShlCircular::getString()
{
	return Strings::Hexus_Cards_ShiftLeftCircular::create();
}

std::string SpecialShlCircular::getIconResource()
{
	return ItemResources::Collectables_Cards_CardSpecial;
}

std::string SpecialShlCircular::getSerializationKey()
{
	return SpecialShlCircular::SaveKey;
}

std::string SpecialShlCircular::getCardKey()
{
	return CardKeys::ShiftLeftCircular;
}
