#pragma once
#include <functional>
#include <string>

#include "cocos/math/CCGeometry.h"

class BlockBase;
class BoltBase;
class CipherPuzzleData;
class Connection;
class InputBolt;
class OutputBolt;

class CipherEvents
{
public:
	static const std::string EventLoadCipher;
	static const std::string EventOpenCipher;
	static const std::string EventRequestBlockSpawn;
	static const std::string EventRequestConnectionCreate;
	static const std::string EventConnectionStarted;
	static const std::string EventShowAsciiTable;
	static const std::string EventChangeActiveCipher;
	static const std::string EventChangeDisplayDataType;

	struct CipherLoadArgs
	{
		std::string cipherName;

		CipherLoadArgs(std::string cipherName) : cipherName(cipherName)
		{
		}
	};

	struct CipherOpenArgs
	{
		CipherPuzzleData* cipherPuzzleData;

		CipherOpenArgs(CipherPuzzleData* cipherPuzzleData) : cipherPuzzleData(cipherPuzzleData)
		{
		}
	};

	struct CipherBlockSpawnArgs
	{
		std::function<BlockBase*()> spawnBlockFunc;
		cocos2d::Vec2 spawnCoords;

		CipherBlockSpawnArgs(std::function<BlockBase*()> spawnBlockFunc, cocos2d::Vec2 spawnCoords) : spawnBlockFunc(spawnBlockFunc), spawnCoords(spawnCoords)
		{
		}
	};

	struct CipherConnectionCreateArgs
	{
		BoltBase* sourceBolt;
		Connection* connection;
		cocos2d::Vec2 destination;
		bool handled;

		CipherConnectionCreateArgs(BoltBase* sourceBolt, Connection* connection, cocos2d::Vec2 destination) : sourceBolt(sourceBolt), connection(connection), destination(destination), handled(false)
		{
		}
	};

	struct CipherConnectionStartedArgs
	{
		Connection* connection;

		CipherConnectionStartedArgs(Connection* connection) : connection(connection)
		{
		}
	};

	struct CipherChangeActiveCipherArgs
	{
		std::string input;
		std::string output;

		CipherChangeActiveCipherArgs(std::string input, std::string output) : input(input), output(output)
		{
		}
	};

	enum class DisplayDataType
	{
		Ascii,
		Bin,
		Dec,
		Hex
	};

	struct CipherChangeDisplayDataTypeArgs
	{
		DisplayDataType displayDataType;

		CipherChangeDisplayDataTypeArgs(DisplayDataType displayDataType) : displayDataType(displayDataType)
		{
		}
	};

	static void TriggerLoadCipher(CipherLoadArgs args);
	static void TriggerOpenCipher(CipherOpenArgs args);
	static void TriggerRequestBlockSpawn(CipherBlockSpawnArgs args);
	static void TriggerRequestConnectionCreate(CipherConnectionCreateArgs args);
	static void TriggerConnectionStarted(CipherConnectionStartedArgs args);
	static void TriggerShowAsciiTable();
	static void TriggerChangeActiveCipher(CipherChangeActiveCipherArgs args);
	static void TriggerChangeDisplayDataType(CipherChangeDisplayDataTypeArgs args);
};