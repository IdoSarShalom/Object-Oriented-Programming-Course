#pragma once

#include "MapCell.h"
#include "Player.h"
#include "Prize.h"

// Represent the map of the maze 
class Map
{
public:
	Map();
	~Map();

	Map(const Map& m);

	Map & operator=(const Map & Other);

	// Represent the optional move for each player 
	enum playerMove {
		LEFT,
		RIGHT,
		DOWN,
		UP,
		STAY,
		NUM_OF_MOVES = STAY + 1
	};

	static const char* playerMoveToString(playerMove pm);

	void printMap(const Player* players, int numPlayers, const Prize& prize);

	// return a randomize external room index - from the map 
	int getRandExternalRoomIndex();

	// Return true or false if the current play is valid 
	// A move is valid in case there is a door to the next cell and the next cell exist and active 
	bool isValidMove(const Player& player, Map::playerMove pm, int &dstMapCellInd);

private: 
	// Return whether the input index is in valid range inside the map cells
	bool isMapIndexInRange(int mapCellInd)
	{
		return mapCellInd >= 0 && mapCellInd < _rows * _cols;
	}

private:
	friend class MapFactory;

	static const int _rows = 8; 
	static const int _cols = 8;

	// Hold a 2d matrix of map cells of size 5X5
	MapCell _mapCell[_rows * _cols];

	// Represent the printing resolution for the map 
	const int _xAxisNumCharsForPrint = 9;
	const int _yAxisNumCharsForPrint = 5;
};

