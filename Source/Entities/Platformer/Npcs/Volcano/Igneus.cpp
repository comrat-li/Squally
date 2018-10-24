#include "Igneus.h"

const std::string Igneus::MapKeyNpcIgneus = "igneus";

Igneus* Igneus::deserialize(ValueMap* initProperties)
{
	Igneus* instance = new Igneus(initProperties);

	instance->autorelease();

	return instance;
}

Igneus::Igneus(ValueMap* initProperties) : NpcBase(initProperties,
	Resources::Entities_Platformer_Environment_Volcano_Npcs_Igneus_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Igneus::~Igneus()
{
}