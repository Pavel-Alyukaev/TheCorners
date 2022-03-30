#include "stdafx.h"
#include "ChessBoard.h"

//TODO убрать в конфиг cellSize
ChessBoard::ChessBoard(): m_scale(1.0f), m_cellSize(63)
{
	m_globalPosition = sf::Vector2f(0.f, 0.f);
	//TODO убрать в конфиг
	m_firstCellLocalPosition.x = 127;
	m_firstCellLocalPosition.y = 627;

	// Получаем разрешение экрана, создаем окно SFML и View
	m_resolution.x = sf::VideoMode::getDesktopMode().width;
	m_resolution.y = sf::VideoMode::getDesktopMode().height;
}

void ChessBoard::Init()
{
	// Связываем текстуру и спрайт
	//TODO убрать в конфиг название текстуры
	m_Texture.loadFromFile("board.jpg");
	m_Sprite.setTexture(m_Texture);

	UpdateScale();
}

sf::Vector2f ChessBoard::ConvertCageNumberToGlobalCoordinate(BoardCell currentCell) const
{
	sf::Vector2f result = m_globalPosition;

	result.x += (m_firstCellLocalPosition.x + (currentCell.Col - 1) * m_cellSize) * m_scale;
	result.y += (m_firstCellLocalPosition.y - currentCell.Row * m_cellSize) * m_scale;

	return result;
}

BoardCell ChessBoard::GetCellOnTheRight(BoardCell currentCell) const
{
	currentCell.Col += 1;
	return currentCell;
}

BoardCell ChessBoard::GetCellFromTheTop(BoardCell currentCell) const
{
	currentCell.Row += 1;
	return currentCell;
}

BoardCell ChessBoard::GetCellOnTheLeft(BoardCell currentCell) const
{
	currentCell.Col -= 1;
	return currentCell;
}

BoardCell ChessBoard::GetCellFromTheBottom(BoardCell currentCell) const
{
	currentCell.Row -= 1;
	return currentCell;
}

void ChessBoard::SetScale(float scale)
{
	m_scale = scale;
}

void ChessBoard::UpdateScale()
{
	m_Sprite.setScale(m_scale, m_scale);

	m_globalPosition.x = (m_resolution.x - m_Texture.getSize().x * m_scale) / 2.0;
	m_globalPosition.y = (m_resolution.y - m_Texture.getSize().y * m_scale) / 2.0;

	m_Sprite.setPosition(m_globalPosition);
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

bool ChessBoard::CheckBorder(BoardCell currentCell) const
{
	return currentCell.Col > 0 && currentCell.Col < 9 && currentCell.Row > 0 && currentCell.Row < 9;
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

void ChessBoard::ChangeOcupateCells(BoardCell currentCell)
{
	auto iter = std::find(m_occupiedCells.begin(), m_occupiedCells.end(), currentCell);
	if (iter == m_occupiedCells.end())
	{
		m_occupiedCells.emplace_back(currentCell);
	}
	else
	{
		*iter = GetCellFromTheTop(currentCell);
	}
}

bool ChessBoard::CanMoveToCell(BoardCell currentCell) const
{
	return std::none_of(m_occupiedCells.begin(), m_occupiedCells.end(),
	                    [&currentCell](const auto& item) { return item == currentCell; }) && CheckBorder(currentCell);
}
