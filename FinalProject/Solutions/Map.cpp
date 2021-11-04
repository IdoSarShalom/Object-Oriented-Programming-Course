#include "Map.h"
#include <iostream>
#include <iostream>

using namespace std;


Map::Map()
{
}

Map::~Map()
{
}

Map::Map(const Map& m) 
{
	memcpy(this->_mapCell, m._mapCell, sizeof(this->_mapCell));
}

Map & Map::operator=(const Map & m)
{
	memcpy(this->_mapCell, m._mapCell, sizeof(this->_mapCell));

	return *this;
}

const char* Map::playerMoveToString(playerMove pm)
{
	switch (pm)
	{
	case playerMove::LEFT:
		return "left";
		break;

	case playerMove::RIGHT:
		return "right";
		break;

	case playerMove::UP:
		return "up";
		break;

	case playerMove::DOWN:
		return "down";
		break;

	case playerMove::STAY:
		return "stay in place";
		break;
	}

	return "";
}

void Map::printMap(const Player* players, int numPlayers, const Prize& prize)
{
	for (int j = 0; j < _rows; j++)
	{
		for (int resY = 0; resY < _yAxisNumCharsForPrint; resY++)
		{
			for (int i = 0; i < _cols; i++)
			{
				for (int resX = 0; resX < _xAxisNumCharsForPrint; resX++)
				{	
					if (_mapCell[j * _cols + i].getIsActive())
					{
						if (resY == 0) //print only the upper line 
						{
							if (_mapCell[j * _cols + i].getUpContent() == MapCell::DOOR && resX % 2 == 0) //print every second tav - door ! 
								cout << ' ';
							else 
								cout << '-'; //wall
						}
						else if (resY == _yAxisNumCharsForPrint - 1) //print the lower line 
						{
							if (_mapCell[j * _cols + i].getDownContent() == MapCell::DOOR && resX % 2 == 0) //print every second tav - door !
								cout << ' ';
							else 
								cout << '-';
						}
						else if (resX == 0) //print the left bound of the cell 
						{
							if (_mapCell[j * _cols + i].getLeftContent() == MapCell::DOOR && resY % 2 == 0)
								cout << ' ';
							else 
								cout << '|';
						}
						else if (resX == _xAxisNumCharsForPrint - 1) //print the left bound of the cell
						{
							if (_mapCell[j * _cols + i].getRightContent() == MapCell::DOOR && resY % 2 == 0)
								cout << ' ';
							else
								cout << '|';
						}
						else
						{
							// Print the player index on the map 
							// in case we are at the middle of the cell 
							if (resX == _xAxisNumCharsForPrint / 2 && resY == _yAxisNumCharsForPrint / 2)
							{
								bool isPrintPlayerSymbol = false;
								for (int p = 0; p < numPlayers; p++)
								{
									// If the current player is on the current cell 
									if (players[p].getMapCellIndex() == (j * _cols + i))
									{
										cout << players[p].getPlayerSerialNumber();
										isPrintPlayerSymbol = true;
									}
								}

								// If there is no player - continue to print space 
								if (!isPrintPlayerSymbol)
								{
									cout << ' ';
								}
							}
							else if ((resX == _xAxisNumCharsForPrint / 2 && resY == ((_yAxisNumCharsForPrint / 2) -1)) || 
								(resX == _xAxisNumCharsForPrint / 2 && resY == ((_yAxisNumCharsForPrint / 2) + 1)) || 
								(resX == _xAxisNumCharsForPrint/2 -1 && resY == _yAxisNumCharsForPrint / 2) || 
								(resX == _xAxisNumCharsForPrint / 2 + 1 && resY == _yAxisNumCharsForPrint / 2))
							{
								// Print the prize 
								if (prize.getMapCellIndex() == (j * _cols + i))
								{
									cout << '*';
								}
								else
								{
									cout << ' ';
								}
							}
							else
							{
								cout << ' ';
							}
							
						}
					}
					else
					{
						cout << ' ';
					}
				}	
			}
			cout << endl;
		}
	}
}

int Map::getRandExternalRoomIndex()
{
	// Get all the external rooms 

	int indexes[_cols * _rows];

	int count = 0;
	for (int i = 0; i < _rows * _cols; i++)
	{
		if (_mapCell[i].getIsExternalRoom())
		{
			indexes[count] = i;
			count++;
		}
			
	}

	if (count == 0)
		return -1;

	int selectedIndex = indexes[rand() % count];

	return selectedIndex;
}

bool Map::isValidMove(const Player& player, Map::playerMove pm, int &dstMapCellInd)
{
	int mapCellInd = player.getMapCellIndex();

	bool isValid = _mapCell[mapCellInd].getIsActive();

	dstMapCellInd = 0;
	switch (pm)
	{
	case playerMove::LEFT:
		isValid &= _mapCell[mapCellInd].getLeftContent() == MapCell::DOOR;
		dstMapCellInd = mapCellInd - 1;
		isValid &= isMapIndexInRange(dstMapCellInd);
		if (isValid)
		{
			// Avoid accessing a cell that is not exist 
			isValid &= _mapCell[dstMapCellInd].getIsActive();
		}
		break;

	case playerMove::RIGHT:
		isValid &= _mapCell[mapCellInd].getRightContent() == MapCell::DOOR;
		dstMapCellInd = mapCellInd + 1;
		isValid &= isMapIndexInRange(dstMapCellInd);
		if (isValid)
		{
			// Avoid accessing a cell that is not exist 
			isValid &= _mapCell[dstMapCellInd].getIsActive();
		}
		break;

	case playerMove::UP:
		isValid &= _mapCell[mapCellInd].getUpContent() == MapCell::DOOR;
		dstMapCellInd = mapCellInd - _cols;
		isValid &= isMapIndexInRange(dstMapCellInd);
		if (isValid)
		{
			// Avoid accessing a cell that is not exist 
			isValid &= _mapCell[dstMapCellInd].getIsActive();
		}
		break;

	case playerMove::DOWN:
		isValid &= _mapCell[mapCellInd].getDownContent() == MapCell::DOOR;
		dstMapCellInd = mapCellInd + _cols;
		isValid &= isMapIndexInRange(dstMapCellInd);
		if (isValid)
		{
			// Avoid accessing a cell that is not exist 
			isValid &= _mapCell[dstMapCellInd].getIsActive();
		}
		break;

	case playerMove::STAY:
		break;

	default:
		isValid = false;
		break;
	}

	return isValid;
}