#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class LocalizedString;

class Mummy : public PlatformerFriendly
{
public:
	static Mummy* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;
	
protected:
	Mummy(cocos2d::ValueMap& properties);
	virtual ~Mummy();

private:
	typedef PlatformerFriendly super;
};
