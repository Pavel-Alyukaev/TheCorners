#include "stdafx.h"
#include "Figure.h"

Figure::Figure(): m_scale(1.f), m_step(0.0f), m_Speed(400), m_localMovedPosition(0.0f),
                  m_isSelected(false)
{
	m_currentCell = BoardCell(1, 1);
}

Figure::~Figure() = default;

void Figure::Init()
{
}

BoardCell Figure::GetCurrentCell() const
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

void Figure::SetCurrentPosition(sf::Vector2f position)
{
	m_endPosition = position;
}

void Figure::MovingForward()
{
	if (m_isMoved == false)
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

bool Figure::IsSelected() const
{
	return m_isSelected;
}

bool Figure::IsMoved() const
{
	return m_isMoved;
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
