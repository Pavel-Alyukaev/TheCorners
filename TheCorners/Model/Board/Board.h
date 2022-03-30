// ****************************************************************************
//  Board.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

namespace Model
{
	class Board
	{
	public:
		void Update();
		[[nodiscard]] bool CanMoveToCell(BoardCell currentCell) const;


		bool ThereAreMoves(BoardCell currentCell) const;

		void ChangeOccupiedCell(BoardCell oldCell, BoardCell newCell);

		BoardCell GetCellOnTheRight(BoardCell currentCell) const;
		BoardCell GetCellFromTheTop(BoardCell currentCell) const;
		BoardCell GetCellOnTheLeft(BoardCell currentCell) const;
		BoardCell GetCellFromTheBottom(BoardCell currentCell) const;

	private:

		bool CheckBorder(BoardCell currentCell) const;

		std::vector<BoardCell> m_occupiedCells;
	};
}