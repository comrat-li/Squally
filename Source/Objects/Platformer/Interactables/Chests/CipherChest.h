#pragma once

#include "Objects/Platformer/Interactables/Chests/ChestBase.h"

using namespace cocos2d;

class CipherPuzzleData;

class CipherChest : public ChestBase
{
public:
	static CipherChest* create(cocos2d::ValueMap& properties);

	static const std::string MapKey;

protected:
	CipherChest(cocos2d::ValueMap& properties);
	virtual ~CipherChest();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void onInteract() override;

private:
	typedef ChestBase super;
	
	CipherPuzzleData* buildPuzzleData();
	CipherPuzzleData* cipherPuzzleData;

	static const std::string PropertyInputs;
	static const std::string PropertyRule;
	static const std::string PropertyTokens;
	static const std::string PropertyDataType;
	static const std::string PropertyTutorial;
};
