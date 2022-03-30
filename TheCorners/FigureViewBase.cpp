#include "stdafx.h"
#include "FigureViewBase.h"

#include "ChessBoardView.h"

namespace View
{
FigureViewBase::FigureViewBase(): m_currentPosition({ -1,-1 }), m_isSelected(false)
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
		auto qq = m_board->ConvertCageNumberToGlobalCoordinate(m_currentPosition);
		m_Sprite.setPosition(qq);
	}
}

void FigureViewBase::SetBoard(ChessBoardView* board)
{
	m_board = board;
}
}
