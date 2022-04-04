// ****************************************************************************
//  stdafx.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <list>
#include <memory>

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

	BoardCell(const BoardCell& right) : Col(right.Col), Row(right.Row)
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
		return BoardCell({Col - right.Col, Row - right.Row});
	}

	BoardCell operator +(const BoardCell& right) const
	{
		return BoardCell({Col + right.Col, Row + right.Row});
	}

};

