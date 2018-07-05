#pragma once
#include "cocos2d.h"

#include "Entities/Enemy.h"
#include "Resources.h"

using namespace cocos2d;

class MiteBot : public Enemy
{
public:
	static MiteBot * deserialize(ValueMap* initProperties);

	static const std::string KeyEnemyMiteBot;

private:
	MiteBot(ValueMap* initProperties);
	~MiteBot();
};