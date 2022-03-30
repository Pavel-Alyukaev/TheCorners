#include "stdafx.h"
#include "Board.h"

namespace Model
{
	void Board::Update()
	{
		CalculateCellsFromWhichCanMove();
	}

	void Board::CalculateCellsFromWhichCanMove()
	{
		m_cellsFromWhichCanMove.clear();

		for (auto cell : m_occupiedCells)
		{
			if (ThereAreMoves(cell) == true)
			{
				m_cellsFromWhichCanMove.emplace_back(cell);
			}
		}
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

	bool Board::ThereAreMoves(BoardCell currCell) const
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

	bool Board::CanMoveToCell(BoardCell currentCell) const
	{
		return std::none_of(m_occupiedCells.begin(), m_occupiedCells.end(),
			[&currentCell](const auto& item) { return item == currentCell; }) && CheckBorder(currentCell);
	}
}