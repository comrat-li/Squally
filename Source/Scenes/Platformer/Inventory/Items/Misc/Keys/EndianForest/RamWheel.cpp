#include "RamWheel.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string RamWheel::SaveKey = "ram-wheel";

RamWheel* RamWheel::create()
{
	RamWheel* instance = new RamWheel();

	instance->autorelease();

	return instance;
}

RamWheel::RamWheel() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 0 }}))
{
}

RamWheel::~RamWheel()
{
}

Item* RamWheel::clone()
{
	return RamWheel::create();
}

std::string RamWheel::getItemName()
{
	return RamWheel::SaveKey;
}

LocalizedString* RamWheel::getString()
{
	return Strings::Items_Misc_Keys_RamWheel::create();
}

std::string RamWheel::getIconResource()
{
	return ItemResources::Keys_RamWheel;
}

std::string RamWheel::getSerializationKey()
{
	return RamWheel::SaveKey;
}

