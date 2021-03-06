#include "CopperMalletPlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string CopperMalletPlans::SaveKey = "copper-mallet-plans";

CopperMalletPlans* CopperMalletPlans::create()
{
	CopperMalletPlans* instance = new CopperMalletPlans();

	instance->autorelease();

	return instance;
}

CopperMalletPlans::CopperMalletPlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

CopperMalletPlans::~CopperMalletPlans()
{
}

Item* CopperMalletPlans::craft()
{
	return CopperMallet::create();
}

std::vector<std::tuple<Item*, int>> CopperMalletPlans::getReagentsInternal()
{
	return
	{
		{ Wood::create(), 3 },
		{ Copper::create(), 6 },
	};
}

Item* CopperMalletPlans::clone()
{
	return CopperMalletPlans::create();
}

std::string CopperMalletPlans::getItemName()
{
	return CopperMalletPlans::SaveKey;
}

LocalizedString* CopperMalletPlans::getString()
{
	return Strings::Items_Equipment_Weapons_Maces_CopperMallet::create();
}

std::string CopperMalletPlans::getIconResource()
{
	return ItemResources::Misc_SCROLL_1;
}

std::string CopperMalletPlans::getCraftedItemIconResource()
{
	return ItemResources::Equipment_Weapons_Maces_CopperMallet;
}

std::string CopperMalletPlans::getSerializationKey()
{
	return CopperMalletPlans::SaveKey;
}
