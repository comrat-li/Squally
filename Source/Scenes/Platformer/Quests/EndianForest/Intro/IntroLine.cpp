#include "IntroLine.h"

#include "Engine/Quests/QuestTask.h"
#include "Scenes/Platformer/Quests/EndianForest/Intro/MeetFlyBot.h"
#include "Scenes/Platformer/Quests/EndianForest/Intro/HelpSquallyHeal.h"
#include "Scenes/Platformer/Quests/EndianForest/Intro/SpotOrcGrunt.h"
#include "Scenes/Platformer/Quests/EndianForest/Intro/TeachHackerMode.h"

using namespace cocos2d;

const std::string IntroLine::MapKeyQuestLine = "intro";

IntroLine* IntroLine::create(std::string quest, std::string questTag, GameObject* owner)
{
	IntroLine* instance = new IntroLine(quest, questTag, owner);
	
	instance->autorelease();

	return instance;
}

IntroLine::IntroLine(std::string quest, std::string questTag, GameObject* owner) : super(
	IntroLine::MapKeyQuestLine,
	quest,
	questTag,
	{
		(QuestTask*)MeetFlyBot::create(quest == MeetFlyBot::MapKeyQuest ? owner : nullptr, IntroLine::MapKeyQuestLine),
		(QuestTask*)HelpSquallyHeal::create(quest == HelpSquallyHeal::MapKeyQuest ? owner : nullptr, IntroLine::MapKeyQuestLine),
		(QuestTask*)TeachHackerMode::create(quest == TeachHackerMode::MapKeyQuest ? owner : nullptr, IntroLine::MapKeyQuestLine),
		(QuestTask*)SpotOrcGrunt::create(quest == SpotOrcGrunt::MapKeyQuest ? owner : nullptr, IntroLine::MapKeyQuestLine),
	})
{
}

IntroLine::~IntroLine()
{
}

void IntroLine::initializePositions()
{
	super::initializePositions();
}

void IntroLine::initializeListeners()
{
	super::initializeListeners();
}
