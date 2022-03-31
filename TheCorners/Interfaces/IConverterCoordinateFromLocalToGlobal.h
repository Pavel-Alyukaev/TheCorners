// ****************************************************************************
//  IConverterCoordinateFromLocalToGlobal.h
//  Интерфейс конвертера координат
// ****************************************************************************

#pragma once

class IConverterCoordinateFromLocalToGlobal
{
public:
	virtual sf::Vector2f ConvertCageNumberToGlobalCoordinate(BoardCell currentCell) const = 0;
};
