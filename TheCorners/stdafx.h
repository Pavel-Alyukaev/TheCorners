// ****************************************************************************
//  stdafx.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

#include <SFML/Graphics.hpp>

struct BoardCell
{
	int Col;
	int Row;

	BoardCell() : Col(1), Row(1)
	{
	}

	BoardCell(int col, int row) : Col(col), Row(row)
	{
	}

	bool operator ==(const BoardCell& right)
	{
		return Row == right.Row && Col == right.Col;
	}

	bool operator ==(const BoardCell& right) const
	{
		return Row == right.Row && Col == right.Col;
	}

	BoardCell operator -(const BoardCell& right) const
	{
		return BoardCell({ Row - right.Row, Col - right.Col });
	}
};
