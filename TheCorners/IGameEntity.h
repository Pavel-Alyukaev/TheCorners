// ****************************************************************************
//  IGameEntity.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

#include <SFML/Graphics.hpp>

class IGameEntity
{
public:
	virtual sf::Vector2i GetCurrentPosition() = 0;

	virtual void SetCurrentPosition(sf::Vector2i) = 0;
};
