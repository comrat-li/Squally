#pragma once

#include "Objects/Platformer/Projectiles/Projectile.h"

namespace cocos2d
{
	class Sprite;
}

class CollisionObject;

class Dart : public Projectile
{
public:
	static Dart* create(float dartRotation, float speed);

	void reset();
	void disable();
	void enable();

protected:
	Dart(float dartRotation, float speed);
	virtual ~Dart();

	void onEnter() override;

private:
	typedef Projectile super;

	CollisionObject* collision;
	cocos2d::Sprite* dartSprite;
	float dartRotation;
	float dartSpeed;
};