// ****************************************************************************
//  Board.h
//  Класс игровой доски
// ****************************************************************************

#pragma once

namespace Model
{
	class Board
	{
	public:
		void Update();
		bool CanMoveToCell(BoardCell currentCell) const;


		bool ThereAreMoves(BoardCell currentCell) const;

		void ChangeOccupiedCell(BoardCell oldCell, BoardCell newCell);

		[[nodiscard]] BoardCell GetCellOnTheRight(BoardCell currentCell) const;
		[[nodiscard]] BoardCell GetCellFromTheTop(BoardCell currentCell) const;
		[[nodiscard]] BoardCell GetCellOnTheLeft(BoardCell currentCell) const;
		[[nodiscard]] BoardCell GetCellFromTheBottom(BoardCell currentCell) const;

		void Deinit();

	private:
		bool CheckBorder(BoardCell currentCell) const;

		std::vector<BoardCell> m_occupiedCells;
	};
}
