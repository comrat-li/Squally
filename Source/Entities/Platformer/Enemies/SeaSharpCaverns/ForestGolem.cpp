////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "ForestGolem.h"

#include "Resources/EntityResources.h"

const std::string ForestGolem::MapKeyForestGolem = "forest-golem";

ForestGolem* ForestGolem::deserialize(cocos2d::ValueMap* initProperties)
{
	ForestGolem* instance = new ForestGolem(initProperties);

	instance->autorelease();

	return instance;
}

ForestGolem::ForestGolem(cocos2d::ValueMap* initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_SeaSharpCaverns_ForestGolem_Animations,
	PlatformerCollisionType::Enemy,
	cocos2d::Size(768.0f, 840.0f),
	0.30f,
	cocos2d::Vec2(0.0f, -420.0f))
{
}

ForestGolem::~ForestGolem()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////