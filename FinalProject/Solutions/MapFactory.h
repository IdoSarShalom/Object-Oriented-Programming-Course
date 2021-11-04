#pragma once

#include "Map.h"

class MapFactory
{
public:
	// Create randomize map and return the index of the randomize map, the index start from 1 to N, where N is the number of maps 
	static Map CreateRandomizeMap(int& mapIndex);

	static int getNumOfMaps()
	{
		return 5;
	}

private: 
	static Map createMap1();
	static Map createMap2();
	static Map createMap3();
	static Map createMap4();
	static Map createMap5();
};

