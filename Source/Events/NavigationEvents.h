#pragma once
#include "cocos2d.h"

#include "Engine/Maps/SerializableMap.h"
#include "Entities/Player/Player.h"
#include "Entities/Enemy.h"
#include "Resources.h"

using namespace cocos2d;

// Forward declarations
class Player;
class Enemy;
class SerializableMap;

class NavigationEvents
{
public:
	static const std::string gameNavigateNewEvent;
	static const std::string gameNavigateBackEvent;
	static const std::string gameNavigateConfirmEvent;
	static const std::string gameNavigateLoadLevelEvent;
	static const std::string gameNavigateEnterLevelEvent;
	static const std::string gameNavigateFightEvent;

	enum GameScreen {
		Title,
		StoryMap,
		Tutorial,
		Pause,
		Options,
		Confirm,
		Loading,
		Level,
		LevelEditor,
		Fight,
		Hexus,
	};

	struct NavigateBackEventArgs
	{
		int backCount;

		NavigateBackEventArgs(int backCount) : backCount(backCount) { };
	};

	struct NavigateEventArgs
	{
		GameScreen gameScreen;

		NavigateEventArgs(GameScreen gameScreen) : gameScreen(gameScreen) { }
	};

	struct NavigateLoadLevelArgs
	{
		std::string levelFile;

		NavigateLoadLevelArgs(std::string levelFile) : levelFile(levelFile) { }
	};

	struct NavigateEnterLevelArgs
	{
		SerializableMap* levelMap;

		NavigateEnterLevelArgs(SerializableMap* levelMap) : levelMap(levelMap) { }
	};

	struct NavigateFightArgs
	{
		Player* player;
		Enemy* enemy;

		NavigateFightArgs(Player*player, Enemy* enemy) : player(player), enemy(enemy) { }
	};

	struct NavigateConfirmArgs
	{
		std::string message;
		std::function<void()> confirmCallback;
		std::function<void()> cancelCallback;

		NavigateConfirmArgs(std::string message, std::function<void()> confirmCallback, std::function<void()> cancelCallback) :
			message(message), confirmCallback(confirmCallback), cancelCallback(cancelCallback) { }
	};

	static void navigateBack(int count = 1);
	static void navigate(GameScreen gameScreen);
	static void navigateConfirm(std::string confirmMessage, std::function<void()> confirmCallback, std::function<void()> cancelCallback);
	static void loadLevel(std::string levelFile);
	static void enterLevel(SerializableMap* levelMap);
	static void loadFight(Player* player, Enemy* enemy);
};
