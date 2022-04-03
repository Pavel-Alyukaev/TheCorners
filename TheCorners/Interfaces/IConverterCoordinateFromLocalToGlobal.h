// ****************************************************************************
//  IConverterCoordinateFromLocalToGlobal.h
//  Интерфейс конвертера координат
// ****************************************************************************

#pragma once

class IConverterCoordinateFromLocalToGlobal
{
public:
	virtual sf::Vector2f ConvertCellNumberToGlobalCoordinate(BoardCell currentCell) const = 0;
};
