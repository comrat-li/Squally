#include "Gargoyle.h"

const std::string Gargoyle::KeyEnemyGargoyle = "gargoyle";

Gargoyle* Gargoyle::deserialize(ValueMap* initProperties)
{
	Gargoyle* instance = new Gargoyle(initProperties);

	instance->autorelease();

	return instance;
}

Gargoyle::Gargoyle(ValueMap* initProperties) : PlatformerEnemy(initProperties,
	Resources::Entities_Platformer_Environment_Obelisk_Enemies_Gargoyle_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(256.0f, 256.0f),
	1.0f,
	Vec2(-32.0f, -24.0f))
{
}

Gargoyle::~Gargoyle()
{
}