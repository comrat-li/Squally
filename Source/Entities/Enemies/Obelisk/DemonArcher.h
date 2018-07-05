#pragma once
#include "cocos2d.h"

#include "Entities/Enemy.h"
#include "Resources.h"

using namespace cocos2d;

class DemonArcher : public Enemy
{
public:
	static DemonArcher * deserialize(ValueMap* initProperties);

	static const std::string KeyEnemyDemonArcher;

private:
	DemonArcher(ValueMap* initProperties);
	~DemonArcher();
};