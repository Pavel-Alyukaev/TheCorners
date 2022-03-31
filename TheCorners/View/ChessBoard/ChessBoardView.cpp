#include "stdafx.h"
#include "ChessBoardView.h"

namespace View
{
	ChessBoardView::ChessBoardView()
	{
		//TODO убрать в конфиг
		m_firstCellLocalPosition.x = 127;
		m_firstCellLocalPosition.y = 627;
		m_cellSize = 63;
	}

	void ChessBoardView::Init()
	{
		// Связываем текстуру и спрайт
		m_boardTexture.loadFromFile("Resource/board.jpg");
		m_Sprite.setTexture(m_boardTexture);
	}

	sf::Vector2u ChessBoardView::GetSize() const
	{
		return m_boardTexture.getSize();
	}

	void ChessBoardView::CalculateAndSetGlobalPosition(sf::Vector2u windowResolution)
	{
		m_globalPosition = (static_cast<sf::Vector2f>(windowResolution) - static_cast<sf::Vector2f>(m_boardTexture.
			getSize()) * m_scale) / 2.0f;

		m_Sprite.setPosition(m_globalPosition);
	}

	sf::Vector2f ChessBoardView::ConvertCageNumberToGlobalCoordinate(BoardCell currentCell) const
	{
		sf::Vector2f result = m_globalPosition;

		result.x += (m_firstCellLocalPosition.x + (currentCell.Col - 1) * m_cellSize) * m_scale;
		result.y += (m_firstCellLocalPosition.y - currentCell.Row * m_cellSize) * m_scale;

		return result;
	}
}
