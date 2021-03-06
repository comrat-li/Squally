#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class CollisionObject;
class EntityGroundCollisionBehavior;
class EntityHeadCollisionBehavior;
class EntityMovementBehavior;
class PlatformerEntity;
class WorldSound;

class EntityMovementCollisionBehavior : public AttachedBehavior
{
public:
	static EntityMovementCollisionBehavior* create(GameObject* owner);

	void enableNormalPhysics();
	void enableWaterPhysics();
	cocos2d::Vec2 getVelocity();
	void setVelocity(cocos2d::Vec2 velocity);
	bool hasLeftWallCollision();
	bool hasRightWallCollision();
	bool hasLeftWallCollisionWith(CollisionObject* collisonObject);
	bool hasRightWallCollisionWith(CollisionObject* collisonObject);
	
	CollisionObject* movementCollision;
	CollisionObject* leftCollision;
	CollisionObject* rightCollision;

	static const std::string MapKey;

protected:
	EntityMovementCollisionBehavior(GameObject* owner);
	virtual ~EntityMovementCollisionBehavior();

	void onLoad() override;
	void onDisable() override;
	void update(float dt) override;

private:
	typedef AttachedBehavior super;

	void warpToPosition(cocos2d::Vec3 position, bool warpCamera);
	void buildMovementCollision();
	void buildWallDetectors();
	void tryBind();

	EntityGroundCollisionBehavior* groundCollision;
	EntityHeadCollisionBehavior* headCollision;
	EntityMovementBehavior* movementBehavior;

	PlatformerEntity* entity;

	WorldSound* submergeSound;
	WorldSound* emergeSound;

	bool movementCollisionBound;
	float noEmergeSubmergeSoundCooldown;

	static const float WaterJumpVelocity;
	static const float SwimVerticalDrag;
	static const float StaticFriction;
};
