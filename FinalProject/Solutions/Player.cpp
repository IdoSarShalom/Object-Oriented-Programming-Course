#include "Player.h"
 
using namespace std; 

Player::Player()
{
}

Player::Player(string playerName, int playerSerialNumber) { _playerName = playerName; _playerSerialNumber = playerSerialNumber; }

Player::~Player()
{
}

void Player::setPlayerName(string playerName) { _playerName = playerName; }

void Player::setPlayerScore(int numPoints) { _score= numPoints; }

void Player::setPlayerSerialNumber(int playerSerialNumber) { _playerSerialNumber = playerSerialNumber;  }

void Player::setMapCellIndex(int index)
{
	_mapCellIndex = index;
}

int Player::getMapCellIndex()const
{
	return _mapCellIndex;
}

string Player::getPlayerName() const { return _playerName; }

int Player::getPlayerScore() const { return _score; }

int Player::getPlayerSerialNumber() const { return _playerSerialNumber; }