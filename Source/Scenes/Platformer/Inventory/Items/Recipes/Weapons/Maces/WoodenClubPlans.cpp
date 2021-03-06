#include "WoodenClubPlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string WoodenClubPlans::SaveKey = "wooden-club-plans";

WoodenClubPlans* WoodenClubPlans::create()
{
	WoodenClubPlans* instance = new WoodenClubPlans();

	instance->autorelease();

	return instance;
}

WoodenClubPlans::WoodenClubPlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

WoodenClubPlans::~WoodenClubPlans()
{
}

Item* WoodenClubPlans::craft()
{
	return WoodenClub::create();
}

std::vector<std::tuple<Item*, int>> WoodenClubPlans::getReagentsInternal()
{
	return
	{
		{ Wood::create(), 6 },
	};
}

Item* WoodenClubPlans::clone()
{
	return WoodenClubPlans::create();
}

std::string WoodenClubPlans::getItemName()
{
	return WoodenClubPlans::SaveKey;
}

LocalizedString* WoodenClubPlans::getString()
{
	return Strings::Items_Equipment_Weapons_Maces_WoodenClub::create();
}

std::string WoodenClubPlans::getIconResource()
{
	return ItemResources::Misc_SCROLL_1;
}

std::string WoodenClubPlans::getCraftedItemIconResource()
{
	return ItemResources::Equipment_Weapons_Maces_WoodenClub;
}

std::string WoodenClubPlans::getSerializationKey()
{
	return WoodenClubPlans::SaveKey;
}
