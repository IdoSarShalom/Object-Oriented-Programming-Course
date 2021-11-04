#pragma once


// Represent a cell in the map, the map has many cells 
class MapCell
{
public:
	MapCell();
	~MapCell();

	enum MapCellContent
	{
		DOOR, 
		WALL
	};

	//getters 
	bool getIsActive() const;
	bool getIsExternalRoom() const; 

	MapCell::MapCellContent getRightContent() const;
	MapCell::MapCellContent getLeftContent() const;
	MapCell::MapCellContent getUpContent() const;
	MapCell::MapCellContent getDownContent() const;

	//setters  
	void setActive(bool isActive); // Set cell active - which means it's participate in the map 
	void setIsExternalRoom(bool isExternal);

	void setRightContent(MapCell::MapCellContent content);
	void setLeftContent(MapCell::MapCellContent content);
	void setTopContent(MapCell::MapCellContent content);
	void setBottomContent(MapCell::MapCellContent content);


	//operators 
	MapCell& operator = (const MapCell & cell); 


private: 
	// Represent whether or not the map cell is in use - participate in the map 
	bool _isActive = false; 
	// Represent whether or not the map cell is an external room
	bool _isExternalRoom = false;

	// Default value - wall 
	MapCellContent _right = MapCellContent::WALL;
	MapCellContent _left = MapCellContent::WALL;
	MapCellContent _top = MapCellContent::WALL;
	MapCellContent _bottom = MapCellContent::WALL;
};

