#pragma once

#include "Scenes/Hexus/States/StateBase.h"

class StateAIDecideCard : public StateBase
{
public:
	static StateAIDecideCard* create();

protected:
	StateAIDecideCard();
	virtual ~StateAIDecideCard();
	
	void onBeforeStateEnter(GameState* gameState) override;
	void onStateEnter(GameState* gameState) override;
	void onStateReload(GameState* gameState) override;
	void onStateExit(GameState* gameState) override;

private:
	typedef StateBase super;

	void decideCardRandom(GameState* gameState);
};
