#include "stdafx.h"
#include "Board.h"

namespace Model
{
	void Board::Update()
	{
	}

	BoardCell Board::GetCellOnTheRight(BoardCell currentCell) const
	{
		currentCell.Col += 1;
		return currentCell;
	}

	BoardCell Board::GetCellFromTheTop(BoardCell currentCell) const
	{
		currentCell.Row += 1;
		return currentCell;
	}

	BoardCell Board::GetCellOnTheLeft(BoardCell currentCell) const
	{
		currentCell.Col -= 1;
		return currentCell;
	}

	BoardCell Board::GetCellFromTheBottom(BoardCell currentCell) const
	{
		currentCell.Row -= 1;
		return currentCell;
	}

	bool Board::CheckBorder(BoardCell currentCell) const
	{
		return currentCell.Col > 0 && currentCell.Col < 9 && currentCell.Row > 0 && currentCell.Row < 9;
	}

	bool Board::ThereAreMoves(BoardCell currentCell) const
	{
		BoardCell cell = GetCellFromTheTop(currentCell);
		const bool forward = CanMoveToCell(cell);
		cell = GetCellFromTheBottom(currentCell);
		const bool backward = CanMoveToCell(cell);
		cell = GetCellOnTheLeft(currentCell);
		const bool left = CanMoveToCell(cell);
		cell = GetCellOnTheRight(currentCell);
		const bool right = CanMoveToCell(cell);

		return forward || backward || left || right;
	}

	void Board::ChangeOccupiedCell(BoardCell oldCell, BoardCell newCell)
	{
		const auto iter = std::find(m_occupiedCells.begin(), m_occupiedCells.end(), oldCell);

		iter == m_occupiedCells.end() ? m_occupiedCells.emplace_back(newCell) : *iter = newCell;
	}

	bool Board::CanMoveToCell(BoardCell currentCell) const
	{
		return std::none_of(m_occupiedCells.begin(), m_occupiedCells.end(),
							[&currentCell](const auto& item) { return item == currentCell; }) &&
			CheckBorder(currentCell);
	}
}
