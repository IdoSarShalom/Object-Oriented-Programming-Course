#include "MazeGame.h"
#include "MapFactory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>  // isdigit()
#include <sstream>  // stringstream
#include<ctype.h> //isalpha()
#include <time.h>

using namespace std; 


MazeGame::MazeGame()
{
	srand(time(nullptr));
}

MazeGame::~MazeGame()
{
	delete[] _playersArr;
}

void MazeGame::startGame()
{	
	printGameIntro();

	getGameTypeFromUser();
	
	initPlayersBuffer();

	// A game is consist of several rounds 
	bool isContinuePlaying = true;
	int gameCounter = 0;
	while (isContinuePlaying)
	{
		gameCounter++;

		initializeMap();

		initPlayersLocation();

		initializePrize();

		int roundCounter = 0;
		bool isFinishedGame = false;
		while (!isFinishedGame)
		{
			roundCounter++;

			isFinishedGame = playRound(isFinishedGame, roundCounter);

			// Print all players score 
			printPlayersScores();
		}

		isContinuePlaying = isContinueToNextGame(isContinuePlaying);
	}

	cout << "Thank you for playing, goodbye!" << endl;
}

bool MazeGame::isContinueToNextGame(bool isContinuePlaying)
{
	// Ask the user whether he would like to play another game? 
	bool bContinue = false;
	while (!bContinue)
	{
		cout << "The current game has finished, would you like to play another game?" << endl;
		cout << "(The map will be chosen randomly, the number of players and the players score stays the same)" << endl;
		cout << "\t type 'n' - for playing another game" << endl;
		cout << "\t type 'q' - for exit the game" << endl;

		string mystr;
		getline(cin, mystr);

		bool isInvalidInput = true;

		// Check the input validity 
		if (mystr.length() == 1)
		{
			switch (mystr[0])
			{
			case 'n':
				isContinuePlaying = true;
				isInvalidInput = false;
				break;

			case 'q':
				isContinuePlaying = false;
				isInvalidInput = false;
				break;
			}
		}

		if (isInvalidInput)
		{
			cout << "You input is not valid, Please try again" << endl;
		}
		else
		{
			bContinue = true;
		}

		cout << endl << endl;
	}		return isContinuePlaying;
}

void MazeGame::printPlayersScores()
{
	cout << "Players scores:" << endl;
	for (int pIndex = 0; pIndex < _numPlayers; pIndex++)
	{
		cout << "\tPlayer number " + to_string(_playersArr[pIndex].getPlayerSerialNumber()) +
			" score is " + to_string(_playersArr[pIndex].getPlayerScore()) << endl;
	}
}

bool MazeGame::playRound(bool isFinishedGame, int roundCounter)
{
	for (int p = 0; p < _numPlayers && !isFinishedGame; p++)
	{
		printMap();

		int mapCellNewIndex = 0;
		bool isValidMove = false;
		Map::playerMove pm;
		while (!isValidMove)
		{
			cout << "Round number " + std::to_string(roundCounter) +
				",\tPlayer number " + std::to_string(_playersArr[p].getPlayerSerialNumber()) + " turn" << endl;

			if (_gameType == gameType::ONE_MANUAL_PLAYER)
			{
				pm = getPlayerMoveFromUser();
			}
			else
			{
				// Get randomize input 
				// 0 - left, 1 - right, 2 - bottom, 3 - up ....
				int pmInt = rand() % Map::playerMove::NUM_OF_MOVES;
				pm = (Map::playerMove)pmInt;
			}

			cout << "Player number " + std::to_string(_playersArr[p].getPlayerSerialNumber()) + " choose to go: "
				<< Map::playerMoveToString(pm) << endl;

			isValidMove = _map.isValidMove(_playersArr[p], pm, mapCellNewIndex);

			if (!isValidMove)
			{
				cout << "Player number " + std::to_string(_playersArr[p].getPlayerSerialNumber()) + " move is not valid" << endl;
				cout << "\tPlease try again" << endl;
			}
		}

		if (pm != Map::playerMove::STAY)
		{
			_playersArr[p].setMapCellIndex(mapCellNewIndex);
			_playersArr[p].setPlayerScore(_playersArr[p].getPlayerScore() - 1);
		}

		isFinishedGame = isGameFinish();

		if (isFinishedGame)
		{
			printMap();
			cout << "Congratulations!!! Player number " + std::to_string(_playersArr[p].getPlayerSerialNumber())
				+ " has won the prize!!!!" << endl;
			cout << "\tCurrent prize is " + to_string(_prize.getPrizeScore()) << endl;

			// Update the player with the prize score
			_playersArr[p].setPlayerScore(_playersArr[p].getPlayerScore() + _prize.getPrizeScore());
		}
	}

	return isFinishedGame;
}

Map::playerMove MazeGame::getPlayerMoveFromUser()
{
	// Get the input from the user 

	Map::playerMove pm = Map::playerMove::UP;

	bool bStop = false;
	while (!bStop)
	{
		cout << "Please insert the player next move:" << endl;
		cout << "\ttype 'a' for left" << endl;
		cout << "\ttype 'd' for right" << endl;
		cout << "\ttype 'w' for up" << endl;
		cout << "\ttype 's' for down" << endl;
		cout << "\ttype 'f' for stay in the same place" << endl;

		string mystr;
		getline(cin, mystr);

		bool isInvalidInput = true;

		// Check the input validity 
		if (mystr.length() == 1)
		{
			switch (mystr[0])
			{
			case 'a':
				pm = Map::playerMove::LEFT;
				isInvalidInput = false;
				break;

			case 'd':
				pm = Map::playerMove::RIGHT;
				isInvalidInput = false;
				break;

			case 'w':
				pm = Map::playerMove::UP;
				isInvalidInput = false;
				break;

			case 's':
				pm = Map::playerMove::DOWN;
				isInvalidInput = false;
				break;

			case 'f':
				pm = Map::playerMove::STAY;
				isInvalidInput = false;
				break;
			}
		}

		if (isInvalidInput)
		{
			cout << "Your input is not valid, Please try again" << endl;
		}
		else
		{
			bStop = true;
		}

		cout << endl << endl;
	}

	return pm;
}

void MazeGame::getGameTypeFromUser()
{
	// Read the game type 
	bool isPickedGameType = false;
	while (!isPickedGameType)
	{
		cout << "Please choose the game type:" << endl;
		cout << "\t type '1' - for individual game" << endl;
		cout << "\t type '2' - for automatic game" << endl;

		string mystr;
		getline(cin, mystr);

		bool isInvalidInput = true;

		// Check the input validity 
		if (mystr.length() == 1)
		{
			switch (mystr[0])
			{
			case '1':
				_gameType = gameType::ONE_MANUAL_PLAYER;
				isInvalidInput = false;
				break;

			case '2':
				_gameType = gameType::AUTOMATIC_GAME;
				isInvalidInput = false;
				break;
			}
		}

		if (isInvalidInput)
		{
			cout << "You input is not valid, Please try again" << endl;
		}
		else
		{
			isPickedGameType = true;
		}

		cout << endl << endl;
	}

	// For automatic game - get the number of players from the user 
	if (_gameType == gameType::ONE_MANUAL_PLAYER)
	{
		_numPlayers = 1;
	}
	else // if (_gameType == gameType::AUTOMATIC_GAME)
	{
		getNumPlayersFromUser();
	}
}

void MazeGame::getNumPlayersFromUser()
{
	bool isGotNumPlayers = false;
	while (!isGotNumPlayers)
	{
		cout << "please enter the number of players (valid range of values is 1-5)" << endl;

		string mystr;
		getline(cin, mystr);

		bool isInvalidInput = true;

		// Check the input validity 
		if (mystr.length() == 1)
		{
			switch (mystr[0])
			{
			case '1':
				_numPlayers = 1;
				isInvalidInput = false;
				break;

			case '2':
				_numPlayers = 2;
				isInvalidInput = false;
				break;

			case '3':
				_numPlayers = 3;
				isInvalidInput = false;
				break;

			case '4':
				_numPlayers = 4;
				isInvalidInput = false;
				break;

			case '5':
				_numPlayers = 5;
				isInvalidInput = false;
				break;
			}
		}

		if (isInvalidInput)
		{
			cout << "You input is not valid, Please try again" << endl;
		}
		else
		{
			isGotNumPlayers = true;
		}

		cout << endl << endl;
	}
}

void MazeGame::printGameIntro()
{
	string intro = R"(
		88888888888888888888888888888888888888888888888888888888888888888888888
		88.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ -  .'|   |.'|     |  _..88
		88   `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-  .'  |.;'   |   _.!-'|  88
		88      | `-!._  |  `;!  ;. _______________ ,'| .-' |   _!.i'     |  88
		88..__  |     |`-!._ | `.| |_______________||."'|  _!.;'   |     _|..88
		88   |``"..__ |    |`";.| i|_|MMMMMMMMMMM|_|'| _!-|   |   _|..-|'    88
		88   |      |``--..|_ | `;!|l|MMoMMMMoMMM|1|.'j   |_..!-'|     |     88
		88   |      |    |   |`-,!_|_|MMMMP'YMMMM|_||.!-;'  |    |     |     88
		88___|______|____!.,.!,.!,!|d|MMMo * loMM|p|,!,.!.,.!..__|_____|_____88
		88      |     |    |  |  | |_|MMMMb,dMMMM|_|| |   |   |    |      |  88
		88      |     |    |..!-;'i|r|MPYMoMMMMoM|r| |`-..|   |    |      |  88
		88      |    _!.-j'  | _!,"|_|M<>MMMMoMMM|_||!._|  `i-!.._ |      |  88
		88     _!.-'|    | _."|  !;|1|MbdMMoMMMMM|l|`.| `-._|    |``-.._  |  88
		88..-i'     |  _.''|  !-| !|_|MMMoMMMMoMM|_|.|`-. | ``._ |     |``"..88
		88   |      |.|    |.|  !| |u|MoMMMMoMMMM|n||`. |`!   | `".    |     88
		88   |  _.-'  |  .'  |.' |/|_|MMMMoMMMMoM|_|! |`!  `,.|    |-._|     88
		88  _!"'|     !.'|  .'| .'|[@]MMMMMMMMMMM[@] \|  `. | `._  |   `-._  88
		88-'    |   .'   |.|  |/| /                 \|`.  |`!    |.|      |`-88
		88      |_.'|   .' | .' |/                   \  \ |  `.  | `._-Lee|  88
		88     .'   | .'   |/|  /                     \ |`!   |`.|    `.  |  88
		88  _.'     !'|   .' | /                       \|  `  |  `.    |`.|  88
		88 Maze            8888888888888888888888888888888888888888888888888888)";

	cout << intro << endl;

	// Print game introductions 
	// Every section is divided by two new lines 
	cout << "Welcome to the best maze game in the world !!!" << endl;
	cout << "\tDevelped by Ido Sar Shalom ID: 212410146 " << endl << endl;

	cout << "Introductions to the game:" << endl;
	cout << "The game contains " << MapFactory::getNumOfMaps() << " different predefined maps. the maps are chosen randomly" << endl;
	cout << "The initial location for each players in the maps is also chosen randomly" << endl;
	cout << "For each map there is a single prize. the prize location is randomly chosen" << endl; 
	cout << "The prize value is randomly chosen between " + to_string(_prizeRangeFrom) + "-" + 
		to_string(_prizeRangeTo) + " points" << endl; 
	cout << endl;

	cout << "There are two game types:" << endl;
	cout << "\t1. Individual game - There is a single manual player that run by the user's keyboard" << endl;
	cout << "\t2. Automatic game - There are multiple bot players. Each move is chosen randomly" << endl;
	cout << "\t   (There is no manual user in this game)" << endl << endl;
}

bool MazeGame::isGameFinish()
{
	for (int q = 0; q < _numPlayers; q++)
	{
		if (_prize.getMapCellIndex() == _playersArr[q].getMapCellIndex())
		{
			return true;
		}			
	}
	return false;
}

void MazeGame::setPlayersArray(const Player* playersArr, int numPlayers)
{
	delete[] _playersArr;
	_playersArr = nullptr; 
	_numPlayers = 0;

	playersArr = new Player[numPlayers];
	for (int i = 0; i < numPlayers; i++)
	{
		_playersArr[i] = playersArr[i];
	}
	_numPlayers = numPlayers;
}

void MazeGame::initPlayersBuffer()
{
	delete[]_playersArr;
	_playersArr = new Player[_numPlayers];

	for (int i = 0; i < _numPlayers; i++)
	{
		_playersArr[i].setPlayerSerialNumber(i+1);
	}
}

void MazeGame::initPlayersLocation()
{
	for (int i = 0; i < _numPlayers; i++)
	{
		int playerStartIndex = _map.getRandExternalRoomIndex();
		_playersArr[i].setMapCellIndex(playerStartIndex);
	}
}

void MazeGame::initializeMap()
{	 
	int randMapIndex;
	_map = MapFactory::CreateRandomizeMap(randMapIndex);

	cout << "Randomize operation picked maze number " + to_string(randMapIndex) << endl;
}

void MazeGame::initializePrize()
{
	// Initialize the prize location 
	// we need to randomize a cell index which is not the location of a player 
	int randIndex = -1;
	while (randIndex == -1)
	{
		randIndex = _map.getRandExternalRoomIndex();
		//  check if the current index has been picked before 
		for (int qq = 0; qq < _numPlayers; qq++)
		{
			if (randIndex == _playersArr[qq].getMapCellIndex())
			{
				randIndex = -1;
				break;
			}
		}
	}

	_prize.setMapCellIndex(randIndex);

	int prizeValue = (rand() % (_prizeRangeTo - _prizeRangeFrom)) + _prizeRangeFrom;
	_prize.setPrizeScore(prizeValue);

	cout << "Prize randomize value is: " + to_string(prizeValue) << endl;
}

void MazeGame::printMap()
{
	_map.printMap(_playersArr, _numPlayers, _prize);
}