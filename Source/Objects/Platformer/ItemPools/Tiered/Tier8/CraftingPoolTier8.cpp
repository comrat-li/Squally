#include "CraftingPoolTier8.h"

#include "cocos/base/CCValue.h"

#include "Engine/Inventory/ItemChance.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

using namespace cocos2d;

CraftingPoolTier8* CraftingPoolTier8::create(SampleMethod sampleMethod, int min, int max)
{
	CraftingPoolTier8* instance = new CraftingPoolTier8(sampleMethod, min, max);

	instance->autorelease();

	return instance;
}

CraftingPoolTier8::CraftingPoolTier8(SampleMethod sampleMethod, int min, int max) : super(ValueMap(), "crafting-pool-t8", sampleMethod, min, max)
{
	// Gems
	this->addItemToPool(ItemChance::create(Obsidian::create(), ItemChance::Probability::Uncommon));

	// Gems (phasing out)
	// this->addItemToPool(ItemChance::create(Quartz::create(), ItemChance::Probability::Legendary));
	// this->addItemToPool(ItemChance::create(Gold::create(), ItemChance::Probability::Legendary));
	// this->addItemToPool(ItemChance::create(Emerald::create(), ItemChance::Probability::Legendary));
	// this->addItemToPool(ItemChance::create(Ruby::create(), ItemChance::Probability::Legendary));
	this->addItemToPool(ItemChance::create(Sapphire::create(), ItemChance::Probability::Legendary));
	this->addItemToPool(ItemChance::create(Sulfur::create(), ItemChance::Probability::Epic));
	this->addItemToPool(ItemChance::create(Diamond::create(), ItemChance::Probability::Rare));

	// Metals
	this->addItemToPool(ItemChance::create(Copper::create(), ItemChance::Probability::Uncommon));
	this->addItemToPool(ItemChance::create(Iron::create(), ItemChance::Probability::Uncommon));
	this->addItemToPool(ItemChance::create(Tin::create(), ItemChance::Probability::Epic));

	// Materials
	this->addItemToPool(ItemChance::create(Coal::create(), ItemChance::Probability::Common));
}

CraftingPoolTier8::~CraftingPoolTier8()
{
}
