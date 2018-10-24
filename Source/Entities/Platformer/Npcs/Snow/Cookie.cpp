#include "Cookie.h"

const std::string Cookie::MapKeyNpcCookie = "cookie";

Cookie* Cookie::deserialize(ValueMap* initProperties)
{
	Cookie* instance = new Cookie(initProperties);

	instance->autorelease();

	return instance;
}

Cookie::Cookie(ValueMap* initProperties) : NpcBase(initProperties,
	Resources::Entities_Platformer_Environment_Snow_Npcs_Cookie_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Cookie::~Cookie()
{
}