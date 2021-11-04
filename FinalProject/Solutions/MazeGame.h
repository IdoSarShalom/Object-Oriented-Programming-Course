#pragma once

#include "Map.h"
#include "Player.h"
#include "Prize.h"


// Hold a representation for the game 
// this class manage the game work flow, create the number of class and simply manage the whole game 
class MazeGame
{
public:
	// Build a new maze game
	MazeGame();
	~MazeGame();

	// Start the interactive game 
	void startGame();

	// Set the player array from outside, the class would do deep copy for the player array 
	// mainly used for unit testing 
	void setPlayersArray(const Player* playersArr, int numPlayers);

private: 

	// Print all the players scores 
	void printPlayersScores();

	bool playRound(bool isFinishedGame, int roundCounter);

	Map::playerMove getPlayerMoveFromUser();

	void getGameTypeFromUser();

	void getNumPlayersFromUser();

	void printGameIntro();

	// Initialize the number of players and their attributes 
	void initPlayersBuffer();

	void initPlayersLocation();

	// Initialize the map 
	void initializeMap(); 

	void initializePrize();

	void printMap();

	bool isGameFinish();

	// ask the user whether to start a new 
	bool isContinueToNextGame(bool isContinuePlaying);

private: 
	
	int _numPlayers = 0;
	Player* _playersArr = nullptr;

	Prize _prize;

	// Represent the map of the game 
	Map _map;
	int _randMap = 0; // Represent the random map of the current game, Default value 0
	
	// Represent which game is on (case 1 or 2)
	enum gameType {
		AUTOMATIC_GAME,
		ONE_MANUAL_PLAYER
	};
	int _gameType = gameType::ONE_MANUAL_PLAYER;

	const int _prizeRangeFrom = 15;
	const int _prizeRangeTo = 40;
};

