#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Enemy.h"

using namespace cocos2d;

class Bear : public Enemy
{
public:
	static Bear * create();

private:
	Bear();
	~Bear();
};