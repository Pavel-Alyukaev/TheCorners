#include "stdafx.h"
#include "Figure.h"

#include <iostream>

Figure::Figure(): m_isMoved(false), m_scale(1.f), m_isSelected(false)
{
	// Вписываем в переменную скорость Боба
	m_Speed = 400;
	m_localMovedPosition = 0.0f;
	m_step = 0.0f;
	BoardCell currentCell = {1, 1};
	m_currentCell = currentCell;
}

void Figure::Init()
{
    // Связываем текстуру и спрайт
    m_Texture.loadFromFile("wite.png");
    m_TextureSelect.loadFromFile("wite_select.png");
    m_Sprite.setTexture(m_Texture);

    m_Sprite.setScale(m_scale, m_scale);

    if (m_step == 0.0f)
    {
        m_step = m_Texture.getSize().x * m_scale;
    }

}

BoardCell Figure::GetCurrentCell()
{
	return m_currentCell;
}

void Figure::SetCurrentCell(BoardCell position)
{
    if (m_isMoved == false)
    {
	    m_currentCell = position;
    }
}

void Figure::SetCurrentPossition(sf::Vector2f possition) 
{
    m_endPosition = possition;
}

void Figure::MovingForward()
{
    if(m_isMoved == false)
    {
	    m_direction = sf::Vector2i(0, -1);
    	m_isMoved = true;
    }
}

void Figure::MovingLeft()
{
    if (m_isMoved == false)
    {
	    m_direction = sf::Vector2i(-1, 0);
    	m_isMoved = true;
    }
}

void Figure::MovingRight()
{
    if (m_isMoved == false)
    {
	    m_direction = sf::Vector2i(1, 0);
    	m_isMoved = true;
    }
}

void Figure::MovingBackward()
{
    if (m_isMoved == false)
    {
	    m_direction = sf::Vector2i(0, 1);
    	m_isMoved = true;
    }
}

void Figure::Stop()
{
}

void Figure::Select()
{
    m_isSelected = true;
    m_Sprite.setTexture(m_TextureSelect);
}

void Figure::Unselect()
{
    m_isSelected = false;
    m_Sprite.setTexture(m_Texture);
}

bool Figure::IsSelected()
{
    return m_isSelected;
}


void Figure::Update(float elapsedTime)
{

    m_localMovedPosition += m_Speed * elapsedTime;

    if (m_isMoved && m_localMovedPosition <= m_step)
    {
        m_endPosition += m_Speed * elapsedTime * static_cast<sf::Vector2f>(m_direction);
    }

    else
    {
        m_isMoved = false;
        m_localMovedPosition = 0.0f;
    }

    
    // Теперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(m_endPosition);
}

sf::Sprite Figure::GetSprite()
{
	return m_Sprite;
}

void Figure::SetScale(float scale)
{
    m_scale = scale;
}

void Figure::SetStep(float step)
{
    m_step = step;
}