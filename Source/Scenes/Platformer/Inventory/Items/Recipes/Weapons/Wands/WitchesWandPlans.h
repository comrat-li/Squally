#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Wands/WandRecipe.h"

class WitchesWandPlans : public WandRecipe
{
public:
	static WitchesWandPlans* create();

	Item* craft() override;
	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getCraftedItemIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKey;

protected:
	WitchesWandPlans();
	virtual ~WitchesWandPlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef WandRecipe super;
};
