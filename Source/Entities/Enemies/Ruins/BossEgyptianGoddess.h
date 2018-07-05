#pragma once
#include "cocos2d.h"

#include "Entities/Enemy.h"
#include "Resources.h"

using namespace cocos2d;

class BossEgyptianGoddess : public Enemy
{
public:
	static BossEgyptianGoddess * deserialize(ValueMap* initProperties);

	static const std::string KeyEnemyBossEgyptianGoddess;

private:
	BossEgyptianGoddess(ValueMap* initProperties);
	~BossEgyptianGoddess();
};