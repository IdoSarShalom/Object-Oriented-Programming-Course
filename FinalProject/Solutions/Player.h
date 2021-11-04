#pragma once

#include <iostream>
#include <string> 


// Represent a player in the game, it's name with it's score and a serial number 
// The player hold it's cell number in the map 
class Player
{
public:
	Player();

	Player(std::string playerName, int playerSerialNumber);

	~Player();

	void setPlayerName(std::string playerName);
	std::string getPlayerName() const;

	void setPlayerScore(int numPoints);
	int getPlayerScore() const;

	void setPlayerSerialNumber(int playerSerialNumber);
	int getPlayerSerialNumber() const;
	
	void setMapCellIndex(int index);
	int getMapCellIndex()const;

private: 
	// Player's name 
	std::string _playerName = "No name yet";
	
	// Number of total points 
	int _score = 0; 

	// Player's serial number  
	int _playerSerialNumber = -1;

	int _mapCellIndex = -1;
};

