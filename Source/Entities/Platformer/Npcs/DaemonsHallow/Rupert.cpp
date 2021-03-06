#include "Rupert.h"

#include "cocos/math/CCGeometry.h"

#include "Resources/EntityResources.h"
#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string Rupert::MapKey = "rupert";

Rupert* Rupert::deserialize(ValueMap& properties)
{
	Rupert* instance = new Rupert(properties);

	instance->autorelease();

	return instance;
}

Rupert::Rupert(ValueMap& properties) : super(properties,
	Rupert::MapKey,
	EntityResources::Npcs_DaemonsHallow_Rupert_Animations,
	EntityResources::Npcs_DaemonsHallow_Rupert_Emblem,
	Size(112.0f, 160.0f),
	1.05f,
	Vec2(0.0f, 0.0f))
{
}

Rupert::~Rupert()
{
}

Vec2 Rupert::getDialogueOffset()
{
	return Vec2(0.0f, 0.0f);
}

LocalizedString* Rupert::getEntityName()
{
	return Strings::Platformer_Entities_Names_Npcs_DaemonsHallow_Rupert::create();
}
