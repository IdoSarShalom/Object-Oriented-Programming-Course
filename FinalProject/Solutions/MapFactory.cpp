#include "MapFactory.h"


Map MapFactory::CreateRandomizeMap(int& mapIndex)
{
	// Randomize the number in rage [1, 5] , Each number represent a different map  
	mapIndex = (rand() % MapFactory::getNumOfMaps()) + 1; 

	Map m;

	switch (mapIndex)
	{
	case 1:
		m = MapFactory::createMap1();
		break;

	case 2:
		m = MapFactory::createMap2();
		break;
		
	case 3:
		m = MapFactory::createMap3();
		break;

	case 4:
		m = MapFactory::createMap4();
		break; 

	case 5:
	default:
		m = MapFactory::createMap5();
		break;
	}

	return m;
}

Map MapFactory::createMap1()
{
	Map map;

	//(0,0)
	map._mapCell[0 * map._cols + 0].setActive(true);
	map._mapCell[0 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 0].setBottomContent(MapCell::DOOR);

	//(0,2)
	map._mapCell[0 * map._cols + 2].setActive(true);
	map._mapCell[0 * map._cols + 2].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 2].setBottomContent(MapCell::DOOR);

	//(1,0)
	map._mapCell[1 * map._cols + 0].setActive(true);
	map._mapCell[1 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[1 * map._cols + 0].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 0].setLeftContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 0].setTopContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 0].setBottomContent(MapCell::WALL);

	//(1,1) --> NOT EXTERNAL ROOM 
	map._mapCell[1 * map._cols + 1].setActive(true);
	map._mapCell[1 * map._cols + 1].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 1].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 1].setTopContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 1].setBottomContent(MapCell::DOOR);

	//(1,2)
	map._mapCell[1 * map._cols + 2].setActive(true);
	map._mapCell[1 * map._cols + 2].setIsExternalRoom(true);
	map._mapCell[1 * map._cols + 2].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 2].setTopContent(MapCell::DOOR);

	//(2,1)
	map._mapCell[2 * map._cols + 1].setActive(true);
	map._mapCell[2 * map._cols + 1].setIsExternalRoom(true);
	map._mapCell[2 * map._cols + 1].setTopContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 1].setBottomContent(MapCell::DOOR);

	//(3,0)
	map._mapCell[3 * map._cols + 0].setActive(true);
	map._mapCell[3 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[3 * map._cols + 0].setRightContent(MapCell::DOOR);

	//(3,1)
	map._mapCell[3 * map._cols + 1].setActive(true);
	map._mapCell[3 * map._cols + 1].setIsExternalRoom(true);
	map._mapCell[3 * map._cols + 1].setRightContent(MapCell::DOOR);
	map._mapCell[3 * map._cols + 1].setLeftContent(MapCell::DOOR);
	map._mapCell[3 * map._cols + 1].setTopContent(MapCell::DOOR);

	//(3,2)
	map._mapCell[3 * map._cols + 2].setActive(true);
	map._mapCell[3 * map._cols + 2].setIsExternalRoom(true);
	map._mapCell[3 * map._cols + 2].setLeftContent(MapCell::DOOR);

	return map;
}

Map MapFactory::createMap2()
{
	Map map;

	//(0,1)
	map._mapCell[0 * map._cols + 1].setActive(true);
	map._mapCell[0 * map._cols + 1].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 1].setRightContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 1].setLeftContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 1].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 1].setBottomContent(MapCell::WALL);

	//(0,2)
	map._mapCell[0 * map._cols + 2].setActive(true);
	map._mapCell[0 * map._cols + 2].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 2].setRightContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 2].setLeftContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 2].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 2].setBottomContent(MapCell::WALL);

	//(0,3) 
	map._mapCell[0 * map._cols + 3].setActive(true);
	map._mapCell[0 * map._cols + 3].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 3].setRightContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 3].setLeftContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 3].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 3].setBottomContent(MapCell::DOOR);

	//(0,4)
	map._mapCell[0 * map._cols + 4].setActive(true);
	map._mapCell[0 * map._cols + 4].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 4].setRightContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 4].setLeftContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 4].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 4].setBottomContent(MapCell::WALL);

	//(1,0)
	map._mapCell[1 * map._cols + 0].setActive(true);
	map._mapCell[1 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[1 * map._cols + 0].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 0].setLeftContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 0].setTopContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 0].setBottomContent(MapCell::DOOR);

	//(1,1)
	map._mapCell[1 * map._cols + 1].setActive(true);
	map._mapCell[1 * map._cols + 1].setIsExternalRoom(true);
	map._mapCell[1 * map._cols + 1].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 1].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 1].setTopContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 1].setBottomContent(MapCell::WALL);

	//(1,2) --> NOT EXTERNAL ROOM 
	map._mapCell[1 * map._cols + 2].setActive(true);
	map._mapCell[1 * map._cols + 2].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 2].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 2].setTopContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 2].setBottomContent(MapCell::WALL);

	//(1,3) --> NOT EXTERNAL ROOM 
	map._mapCell[1 * map._cols + 3].setActive(true);
	map._mapCell[1 * map._cols + 3].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 3].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 3].setTopContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 3].setBottomContent(MapCell::WALL);

	//(1,4)
	map._mapCell[1 * map._cols + 4].setActive(true);
	map._mapCell[1 * map._cols + 4].setIsExternalRoom(true);
	map._mapCell[1 * map._cols + 4].setRightContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 4].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 4].setTopContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 4].setBottomContent(MapCell::DOOR);

	//(2,0)
	map._mapCell[2 * map._cols + 0].setActive(true);
	map._mapCell[2 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[2 * map._cols + 0].setRightContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 0].setLeftContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 0].setTopContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 0].setBottomContent(MapCell::WALL);

	//(2,2)
	map._mapCell[2 * map._cols + 2].setActive(true);
	map._mapCell[2 * map._cols + 2].setIsExternalRoom(true);
	map._mapCell[2 * map._cols + 2].setRightContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 2].setLeftContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 2].setTopContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 2].setBottomContent(MapCell::DOOR);

	//(2,3) --> NOT EXTERNAL ROOM 
	map._mapCell[2 * map._cols + 3].setActive(true);
	map._mapCell[2 * map._cols + 3].setRightContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 3].setLeftContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 3].setTopContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 3].setBottomContent(MapCell::WALL);

	//(2,4)
	map._mapCell[2 * map._cols + 4].setActive(true);
	map._mapCell[2 * map._cols + 4].setIsExternalRoom(true);
	map._mapCell[2 * map._cols + 4].setRightContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 4].setLeftContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 4].setTopContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 4].setBottomContent(MapCell::WALL);

	//(3,2)
	map._mapCell[3 * map._cols + 2].setActive(true);
	map._mapCell[3 * map._cols + 2].setIsExternalRoom(true);
	map._mapCell[3 * map._cols + 2].setRightContent(MapCell::DOOR);
	map._mapCell[3 * map._cols + 2].setLeftContent(MapCell::WALL);
	map._mapCell[3 * map._cols + 2].setTopContent(MapCell::DOOR);
	map._mapCell[3 * map._cols + 2].setBottomContent(MapCell::WALL);

	//(3,3)
	map._mapCell[3 * map._cols + 3].setActive(true);
	map._mapCell[3 * map._cols + 3].setIsExternalRoom(true);
	map._mapCell[3 * map._cols + 3].setRightContent(MapCell::WALL);
	map._mapCell[3 * map._cols + 3].setLeftContent(MapCell::DOOR);
	map._mapCell[3 * map._cols + 3].setTopContent(MapCell::WALL);
	map._mapCell[3 * map._cols + 3].setBottomContent(MapCell::WALL);

	return map;
}

Map MapFactory::createMap3()
{
	Map map;

	//(0,0)
	map._mapCell[0 * map._cols + 0].setActive(true);
	map._mapCell[0 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 0].setRightContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 0].setLeftContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 0].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 0].setBottomContent(MapCell::WALL);

	//(0,1)
	map._mapCell[0 * map._cols + 1].setActive(true);
	map._mapCell[0 * map._cols + 1].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 1].setRightContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 1].setLeftContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 1].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 1].setBottomContent(MapCell::WALL);

	//(0,2) 
	map._mapCell[0 * map._cols + 2].setActive(true);
	map._mapCell[0 * map._cols + 2].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 2].setRightContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 2].setLeftContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 2].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 2].setBottomContent(MapCell::WALL);

	//(0,3)
	map._mapCell[0 * map._cols + 3].setActive(true);
	map._mapCell[0 * map._cols + 3].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 3].setRightContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 3].setLeftContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 3].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 3].setBottomContent(MapCell::DOOR);

	//(0,4)
	map._mapCell[0 * map._cols + 4].setActive(true);
	map._mapCell[0 * map._cols + 4].setIsExternalRoom(true);
	map._mapCell[0 * map._cols + 4].setRightContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 4].setLeftContent(MapCell::DOOR);
	map._mapCell[0 * map._cols + 4].setTopContent(MapCell::WALL);
	map._mapCell[0 * map._cols + 4].setBottomContent(MapCell::WALL);

	//(1,0)
	map._mapCell[1 * map._cols + 0].setActive(true);
	map._mapCell[1 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[1 * map._cols + 0].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 0].setLeftContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 0].setTopContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 0].setBottomContent(MapCell::DOOR);

	//(1,1) --> NOT EXTERNAL ROOM 
	map._mapCell[1 * map._cols + 1].setActive(true);
	map._mapCell[1 * map._cols + 1].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 1].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 1].setTopContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 1].setBottomContent(MapCell::WALL);

	//(1,2) --> NOT EXTERNAL ROOM 
	map._mapCell[1 * map._cols + 2].setActive(true);
	map._mapCell[1 * map._cols + 2].setRightContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 2].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 2].setTopContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 2].setBottomContent(MapCell::DOOR);

	//(1,3)
	map._mapCell[1 * map._cols + 3].setActive(true);
	map._mapCell[1 * map._cols + 3].setIsExternalRoom(true);
	map._mapCell[1 * map._cols + 3].setRightContent(MapCell::WALL);
	map._mapCell[1 * map._cols + 3].setLeftContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 3].setTopContent(MapCell::DOOR);
	map._mapCell[1 * map._cols + 3].setBottomContent(MapCell::WALL);

	//(2,0)
	map._mapCell[2 * map._cols + 0].setActive(true);
	map._mapCell[2 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[2 * map._cols + 0].setRightContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 0].setLeftContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 0].setTopContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 0].setBottomContent(MapCell::DOOR);

	//(2,1) --> NOT EXTERNAL ROOM
	map._mapCell[2 * map._cols + 1].setActive(true);
	map._mapCell[2 * map._cols + 1].setRightContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 1].setLeftContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 1].setTopContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 1].setBottomContent(MapCell::DOOR);

	//(2,2) 
	map._mapCell[2 * map._cols + 2].setActive(true);
	map._mapCell[2 * map._cols + 2].setIsExternalRoom(true);
	map._mapCell[2 * map._cols + 2].setRightContent(MapCell::WALL);
	map._mapCell[2 * map._cols + 2].setLeftContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 2].setTopContent(MapCell::DOOR);
	map._mapCell[2 * map._cols + 2].setBottomContent(MapCell::WALL);

	//(3,0)
	map._mapCell[3 * map._cols + 0].setActive(true);
	map._mapCell[3 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[3 * map._cols + 0].setRightContent(MapCell::WALL);
	map._mapCell[3 * map._cols + 0].setLeftContent(MapCell::WALL);
	map._mapCell[3 * map._cols + 0].setTopContent(MapCell::DOOR);
	map._mapCell[3 * map._cols + 0].setBottomContent(MapCell::DOOR);

	//(3,1)
	map._mapCell[3 * map._cols + 1].setActive(true);
	map._mapCell[3 * map._cols + 1].setIsExternalRoom(true);
	map._mapCell[3 * map._cols + 1].setRightContent(MapCell::WALL);
	map._mapCell[3 * map._cols + 1].setLeftContent(MapCell::WALL);
	map._mapCell[3 * map._cols + 1].setTopContent(MapCell::DOOR);
	map._mapCell[3 * map._cols + 1].setBottomContent(MapCell::WALL);

	//(4,0)
	map._mapCell[4 * map._cols + 0].setActive(true);
	map._mapCell[4 * map._cols + 0].setIsExternalRoom(true);
	map._mapCell[4 * map._cols + 0].setRightContent(MapCell::WALL);
	map._mapCell[4 * map._cols + 0].setLeftContent(MapCell::WALL);
	map._mapCell[4 * map._cols + 0].setTopContent(MapCell::DOOR);
	map._mapCell[4 * map._cols + 0].setBottomContent(MapCell::WALL);

	return map;
}

Map MapFactory::createMap4()
{
	Map map;

	int N = 7;
	for (int i = 0; i < N; i++)
	{
		// Construct left corridor of cells 
		// cell (i,i)
		int numCell = i * map._cols + i;
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setRightContent(MapCell::DOOR);
		map._mapCell[numCell].setTopContent(MapCell::DOOR);

		// Construct right corridor of cells 
		// cell (i,i+1)
		numCell = i * map._cols + (i+1);
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setLeftContent(MapCell::DOOR);
		map._mapCell[numCell].setBottomContent(MapCell::DOOR);
	}

	// Special cases 
	{
		//(0,0)
		int numCell = 0 * map._cols + 0;
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(true);
		// map._mapCell[numCell].setRightContent(MapCell::DOOR);
		map._mapCell[numCell].setLeftContent(MapCell::WALL);
		map._mapCell[numCell].setTopContent(MapCell::WALL);
		map._mapCell[numCell].setBottomContent(MapCell::WALL);
	}

	{
		//(0,0)
		int numCell = (N-1) * map._cols + (N);
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setBottomContent(MapCell::WALL);
	}

	return map;
}

Map MapFactory::createMap5()
{
	Map map;

	int N = 7;
	for (int i = 0; i < N; i++)
	{
		// Horizontal line in the middle of the rows 
		int numCell = (N / 2) * map._cols + i;
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(false);
		map._mapCell[numCell].setRightContent(MapCell::DOOR);
		map._mapCell[numCell].setLeftContent(MapCell::DOOR);

		// Vertical line in the middle of the columns
		numCell = i * map._cols + (N / 2);
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(false);
		map._mapCell[numCell].setTopContent(MapCell::DOOR);
		map._mapCell[numCell].setBottomContent(MapCell::DOOR);

		// Upper row 
		numCell = 0 * map._cols + i;
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setRightContent(MapCell::DOOR);
		map._mapCell[numCell].setLeftContent(MapCell::DOOR);

		// Bottom row 
		numCell = (N-1) * map._cols + i;
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setRightContent(MapCell::DOOR);
		map._mapCell[numCell].setLeftContent(MapCell::DOOR);

		// Left 
		numCell = i * map._cols + 0;
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setTopContent(MapCell::DOOR);
		map._mapCell[numCell].setBottomContent(MapCell::DOOR);

		// Right 
		numCell = i * map._cols + (N-1);
		map._mapCell[numCell].setActive(true);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setTopContent(MapCell::DOOR);
		map._mapCell[numCell].setBottomContent(MapCell::DOOR);
	}

	// Special cases 
	{
		//(0,0)
		int numCell = 0 * map._cols + 0;
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setTopContent(MapCell::WALL);
		map._mapCell[numCell].setLeftContent(MapCell::WALL);
	}

	{
		//(0,N-1)
		int numCell = 0 * map._cols + (N-1);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setTopContent(MapCell::WALL);
		map._mapCell[numCell].setRightContent(MapCell::WALL);
	}

	{
		//(N-1,0)
		int numCell = (N-1) * map._cols + 0;
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setLeftContent(MapCell::WALL);
		map._mapCell[numCell].setBottomContent(MapCell::WALL);
	}

	{
		//(N-1,N-1)
		int numCell = (N - 1) * map._cols + (N - 1);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setRightContent(MapCell::WALL);
		map._mapCell[numCell].setBottomContent(MapCell::WALL);
	}

	{
		//(0,N/2)
		int numCell = (0) * map._cols + (N/2);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setTopContent(MapCell::WALL);
	}

	{
		//(N/2,0)
		int numCell = (N/2) * map._cols + (0);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setLeftContent(MapCell::WALL);
	}

	{
		//(N/2,N/2)
		int numCell = (N / 2) * map._cols + (N-1);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setRightContent(MapCell::WALL);
	}

	{
		//(N-1,N/2)
		int numCell = (N-1) * map._cols + (N / 2);
		map._mapCell[numCell].setIsExternalRoom(true);
		map._mapCell[numCell].setBottomContent(MapCell::WALL);
	}

	return map;
}
