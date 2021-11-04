#pragma once


class Prize
{
public:
	Prize();
	~Prize();

	void setPrizeScore(int score)
	{
		_prizeScore = score;
	}

	int getPrizeScore()
	{
		return _prizeScore;
	}

	void setMapCellIndex(int index)
	{
		_mapCellIndex = index;
	}

	int getMapCellIndex()const
	{
		return _mapCellIndex;
	}

private:
	int _prizeScore; 
	int _mapCellIndex;
};

