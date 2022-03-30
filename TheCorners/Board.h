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
	private:
		void CalculateCellsFromWhichCanMove();


		BoardCell GetCellOnTheRight(BoardCell currentCell) const;
		BoardCell GetCellFromTheTop(BoardCell currentCell) const;
		BoardCell GetCellOnTheLeft(BoardCell currentCell) const;
		BoardCell GetCellFromTheBottom(BoardCell currentCell) const;
		bool CheckBorder(BoardCell currentCell) const;
		bool ThereAreMoves(BoardCell currCell) const;
		bool CanMoveToCell(BoardCell currentCell) const;


		std::vector<BoardCell> m_occupiedCells;
		std::vector<BoardCell> m_cellsFromWhichCanMove;
	};
}