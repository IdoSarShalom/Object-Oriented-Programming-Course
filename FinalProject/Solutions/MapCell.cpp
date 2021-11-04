#include "MapCell.h"


MapCell::MapCell()
{
}

MapCell::~MapCell()
{
}

bool MapCell::getIsActive() const { return _isActive; }

bool MapCell::getIsExternalRoom() const { return _isExternalRoom; }

MapCell::MapCellContent MapCell::getRightContent() const { return _right; }

MapCell::MapCellContent MapCell::getLeftContent() const { return _left; }

MapCell::MapCellContent MapCell::getUpContent() const { return _top; }

MapCell::MapCellContent MapCell::getDownContent() const { return _bottom; }

void MapCell::setActive(bool isActive) { _isActive = isActive; }

void MapCell::setIsExternalRoom(bool isExternal) { _isExternalRoom = isExternal; }

void MapCell::setLeftContent(MapCell::MapCellContent content) { _left = content; }

void MapCell::setRightContent(MapCell::MapCellContent content) { _right = content; }

void MapCell::setTopContent(MapCell::MapCellContent content) { _top = content; }

void MapCell::setBottomContent(MapCell::MapCellContent content) { _bottom = content; }

MapCell& MapCell::operator = (const MapCell & cell)
{
	if (this != &cell)
	{
		_isActive = cell.getIsActive();
		_isExternalRoom = cell.getIsExternalRoom();
		_right = cell.getRightContent();
		_left = cell.getLeftContent();
		_top = cell.getUpContent();
		_bottom = cell.getDownContent();
	}
	return *this; 
}





