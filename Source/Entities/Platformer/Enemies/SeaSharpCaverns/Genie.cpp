//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED. ONLY EDIT NON-GENERATED SECTIONS. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Genie.h"

#include "Resources/EntityResources.h"

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////A////A////A////A////A////A////A////A////A////A/

////B////B////B////B////B////B////B////B////B////B/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

const std::string Genie::MapKeyGenie = "genie";

Genie* Genie::deserialize(cocos2d::ValueMap& initProperties)
{
	Genie* instance = new Genie(initProperties);

	instance->autorelease();

	return instance;
}

Genie::Genie(cocos2d::ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_SeaSharpCaverns_Genie_Animations,
	EntityResources::Enemies_SeaSharpCaverns_Genie_Emblem,
	PlatformerCollisionType::Enemy,
	cocos2d::Size(512.0f, 1126.0f),
	0.20f,
	cocos2d::Vec2(0.0f, 0.0f),
	10,
	10)
{
	///////////////////////////////////////////////////
	// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
	////Y////Y////Y////Y////Y////Y////Y////Y////Y////Y/

	////Z////Z////Z////Z////Z////Z////Z////Z////Z////Z/
	// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
	///////////////////////////////////////////////////
}

Genie::~Genie()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////
