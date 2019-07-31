#include "PlatformerFriendly.h"

using namespace cocos2d;

PlatformerFriendly::PlatformerFriendly(
	ValueMap& properties,
	std::string scmlResource,
	std::string emblemResource,
	PlatformerCollisionType collisionType, 
	Size size, 
	float scale,
	Vec2 collisionOffset,
	int baseHealth,
	int baseSpecial,
	Size movementCollisionSize,
	float ghettoGroundCollisionFix,
	PlatformerCollisionType movementCollisionType,
	std::string inventorySaveKey,
	std::string equipmentSaveKey,
	std::string currencySaveKey
	)
	: super(
		properties,
		scmlResource,
		emblemResource,
		collisionType,
		size,
		scale,
		collisionOffset,
		baseHealth,
		baseSpecial,
		movementCollisionSize,
		ghettoGroundCollisionFix,
		movementCollisionType,
		inventorySaveKey,
		equipmentSaveKey,
		currencySaveKey
	)
{
}

PlatformerFriendly::~PlatformerFriendly()
{
}
