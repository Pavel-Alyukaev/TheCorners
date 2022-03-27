#include "stdafx.h"
#include "ChessBoard.h"

ChessBoard::ChessBoard(): m_scale(1.0f), m_cellSize(63)
{
	m_globalPossition = sf::Vector2f(0.f, 0.f);

	m_firstCellLocalPossition.x = 127;
	m_firstCellLocalPossition.y = 627;

	// Получаем разрешение экрана, создаем окно SFML и View
	m_resolution.x = sf::VideoMode::getDesktopMode().width;
	m_resolution.y = sf::VideoMode::getDesktopMode().height;
}

void ChessBoard::Init()
{
	// Связываем текстуру и спрайт
	m_Texture.loadFromFile("board.jpg");
	m_Sprite.setTexture(m_Texture);

	UpdateScale();

}

sf::Vector2f ChessBoard::ConvertCageNumberToGlobalCoordinate(BoardCell currCell) const
{
	sf::Vector2f result = m_globalPossition;

	result.x += (m_firstCellLocalPossition.x + (currCell.Col - 1) * m_cellSize) * m_scale;
	result.y += (m_firstCellLocalPossition.y - currCell.Row * m_cellSize) * m_scale;

	return result;
}

BoardCell ChessBoard::GetCellOnTheRight(BoardCell currCell) const
{
	currCell.Col += 1;
	return currCell;
}

BoardCell ChessBoard::GetCellFromTheTop(BoardCell currCell)  const
{
	currCell.Row += 1;
	return currCell;
}

BoardCell ChessBoard::GetCellOnTheLeft(BoardCell currCell) const
{
	currCell.Col -= 1;
	return currCell;
}

BoardCell ChessBoard::GetCellFromTheBottom(BoardCell currCell) const
{
	currCell.Row -= 1;
	return currCell;
}

void ChessBoard::SetScale(float scale)
{
	m_scale = scale;
}

void ChessBoard::UpdateScale()
{
	m_Sprite.setScale(m_scale, m_scale);

	m_globalPossition.x = (m_resolution.x - m_Texture.getSize().x * m_scale) / 2.0;
	m_globalPossition.y = 0.05f * m_resolution.y;

	m_Sprite.setPosition(m_globalPossition);
}


sf::Vector2u ChessBoard::GetSize() const
{
	return m_Texture.getSize();
}

sf::Sprite ChessBoard::GetSprite()
{
	return m_Sprite;
}

int ChessBoard::GetCellSize() const
{
	return m_cellSize * m_scale;
}

bool ChessBoard::CheckBorder(BoardCell currCell) const
{
	return currCell.Col > 0 && currCell.Col < 9 && currCell.Row>0 && currCell.Row < 9;
}

bool ChessBoard::ThereAreMoves(BoardCell currCell) const
{
	BoardCell cell = GetCellFromTheTop(currCell);
	const bool forward = CanMoveToCell(cell);
	cell = GetCellFromTheBottom(currCell);
	const bool backward = CanMoveToCell(cell);
	cell = GetCellOnTheLeft(currCell);
	const bool left = CanMoveToCell(cell);
	cell = GetCellOnTheRight(currCell);
	const bool right = CanMoveToCell(cell);

	return forward || backward || left || right;
}

void ChessBoard::ChangeOcupateCells(BoardCell currCell)
{
	auto iter = std::find(m_occupiedCells.begin(), m_occupiedCells.end(), currCell);
	if (iter == m_occupiedCells.end())
	{
		m_occupiedCells.emplace_back(currCell);
	}
	else
	{
		*iter = GetCellFromTheTop(currCell);
	}
}

bool ChessBoard::CanMoveToCell(BoardCell currCell) const
{
	return std::none_of(m_occupiedCells.begin(), m_occupiedCells.end(), [&currCell](const auto& item) {return item == currCell; }) && CheckBorder(currCell);
}


