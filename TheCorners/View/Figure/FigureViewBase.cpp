#include "stdafx.h"
#include "FigureViewBase.h"

#include "../ChessBoard/ChessBoardView.h"

namespace View
{
FigureViewBase::FigureViewBase(): m_currentPosition({-1, -1}), m_isSelected(false), m_speed(300), m_isMoved(false)
{
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
		m_globalCoordinate = m_board->ConvertCageNumberToGlobalCoordinate(m_currentPosition);
		m_Sprite.setPosition(m_globalCoordinate);
	}
	else
	{
		m_isMoved = true;
		m_endPosition = position;
		auto direction = m_endPosition - m_currentPosition;
		m_direction.x = static_cast<float>(direction.Col);
		m_direction.y = -static_cast<float>(direction.Row);
	}
}

void FigureViewBase::SetConverter(IConverterCoordinateFromLocalToGlobal* board)
{
	m_board = board;
}

void FigureViewBase::Update(float elapsedTime)
{
	m_localMovedPosition += m_speed * elapsedTime;

	if (m_isMoved && m_localMovedPosition <= m_step)
	{
		m_globalCoordinate += m_localMovedPosition * (m_direction);

		// Теперь сдвигаем спрайт на новую позицию
		m_Sprite.setPosition(m_globalCoordinate);
	}
	else if (m_isMoved)
	{
		m_localMovedPosition = 0.0f;
		m_localCoordinate = {0.0f, 0.0f};
		m_isMoved = false;
		m_currentPosition = m_endPosition;
		m_globalCoordinate = m_board->ConvertCageNumberToGlobalCoordinate(m_currentPosition);

		// Теперь сдвигаем спрайт на новую позицию
		m_Sprite.setPosition(m_globalCoordinate);
	}
	else
	{
		m_localMovedPosition = 0.0f;
	}
}

BoardCell FigureViewBase::GetCurrentPosition() const
{
	return m_currentPosition;
}

void FigureViewBase::CalculateStep()
{
	const auto globalCoordinate1 = m_board->ConvertCageNumberToGlobalCoordinate({1, 1});

	const auto globalCoordinate2 = m_board->ConvertCageNumberToGlobalCoordinate({1, 2});


	m_step = (globalCoordinate2 - globalCoordinate1).y * m_scale;
}
}
