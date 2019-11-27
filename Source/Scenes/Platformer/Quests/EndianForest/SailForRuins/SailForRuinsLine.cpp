#include "SailForRuinsLine.h"

#include "Engine/Quests/QuestTask.h"
#include "Scenes/Platformer/Quests/EndianForest/FindElriel/FindElrielLine.h"
#include "Scenes/Platformer/Quests/EndianForest/SailForRuins/SailForRuins.h"

using namespace cocos2d;

const std::string SailForRuinsLine::MapKeyQuestLine = "sail-for-ruins";

SailForRuinsLine* SailForRuinsLine::create()
{
	SailForRuinsLine* instance = new SailForRuinsLine();

	instance->autorelease();

	return instance;
}

SailForRuinsLine::SailForRuinsLine() : super(SailForRuinsLine::MapKeyQuestLine,
	{
		QuestData(SailForRuins::MapKeyQuest, false, [](GameObject* owner, QuestLine* questLine, std::string questTag) { return SailForRuins::create(owner, questLine, questTag); }),
	},
	(QuestLine*)FindElrielLine::create())
{
}

SailForRuinsLine::~SailForRuinsLine()
{
}