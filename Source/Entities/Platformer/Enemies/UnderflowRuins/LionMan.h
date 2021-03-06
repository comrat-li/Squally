#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class LocalizedString;

class LionMan : public PlatformerEnemy
{
public:
	static LionMan* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;
	
protected:
	LionMan(cocos2d::ValueMap& properties);
	virtual ~LionMan();

private:
	typedef PlatformerEnemy super;
};
