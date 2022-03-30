#include "stdafx.h"
#include "FigureViewBase.h"

#include "..\ChessBoard\ChessBoardView.h"

namespace View
{
FigureViewBase::FigureViewBase(): m_currentPosition({ -1,-1 }), m_isSelected(false)
{
	m_isMoved = false;
	m_Speed = 400;
	m_step = 400;
}

void FigureViewBase::Init()
{
}


void FigureViewBase::Select()
{
	if (m_isSelected == false)
	{
		m_Sprite.setTexture(m_textureSelect);
		m_isSelected = true;
	}
}

void FigureViewBase::Unselect()
{
	if (m_isSelected == true)
	{
		m_Sprite.setTexture(m_texture);
		m_isSelected = false;
	}
}

void FigureViewBase::MoveTo(sf::Vector2f position)
{
	m_Sprite.setPosition(position);
}

sf::Vector2u FigureViewBase::GetSize() const
{
	return m_texture.getSize();
}

void FigureViewBase::UpdateState()
{
	Select();
}

void FigureViewBase::UpdatePosition(BoardCell position)
{
	if (m_currentPosition.Row <= 0 || m_currentPosition.Col <= 0)
	{
		m_currentPosition = position;
		m_endPosition = position;
		const auto coordinate = m_board->ConvertCageNumberToGlobalCoordinate(m_currentPosition);
		m_Sprite.setPosition(coordinate);
	}
	else
	{
		m_isMoved = true;
		m_endPosition = position;
		auto direction = m_endPosition - m_currentPosition;
		m_direction.x = direction.Col;
		m_direction.y = direction.Row;
	}
}

void FigureViewBase::SetBoard(ChessBoardView* board)
{
	m_board = board;
}

sf::Vector2f FigureViewBase::GetLocalCoordinateToMove(float elapsedTime)
{
	m_localMovedPosition += m_Speed * elapsedTime;

	if (m_isMoved && m_localMovedPosition <= m_step)
	{
		m_localCoordinate = m_localMovedPosition * (m_direction);
		m_Sprite.setPosition(m_localCoordinate);

	}
	else if(m_isMoved)
	{
		m_localMovedPosition = 0.0f;
		m_localCoordinate = { 0.0f ,0.0f };
		m_isMoved = false;
		m_currentPosition = m_endPosition;
		m_Sprite.setPosition(m_localCoordinate);

	}
	else
	{
		m_localMovedPosition = 0.0f;
	}

	//

	// Теперь сдвигаем спрайт на новую позицию
	return m_localCoordinate;
}

BoardCell FigureViewBase::GetCurrentPosition() const
{
	return m_currentPosition;
}
}
