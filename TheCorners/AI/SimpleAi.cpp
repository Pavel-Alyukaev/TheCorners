#include "stdafx.h"
#include "SimpleAi.h"
#include "../Model/Figure/FigureBase.h"

namespace AI
{
	void SimpleAi::Calculate()
	{
		//std::srand(std::time(nullptr)); // use current time as seed for random generator
		//int random_variable = std::rand();
		int iiii = rand() % 9;
		auto iterator = m_figures.begin();

		for (int i = 0; i <= iiii; ++i)
		{
			do
			{
				if (++iterator == m_figures.end())
				{
					iterator = m_figures.begin();
				}
			} while (m_board->ThereAreMoves((*iterator)->GetCurrentCell()) == false);
		}

		m_figure = *iterator;

		std::vector<BoardCell> cells;

		BoardCell cell = m_board->GetCellFromTheTop((*iterator)->GetCurrentCell());
		if (m_board->CanMoveToCell(cell) == true)
		{
			cells.emplace_back(cell);
		}
		cell = m_board->GetCellFromTheBottom((*iterator)->GetCurrentCell());
		if (m_board->CanMoveToCell(cell) == true)
		{
			cells.emplace_back(cell);
		}
		cell = m_board->GetCellOnTheLeft((*iterator)->GetCurrentCell());
		if (m_board->CanMoveToCell(cell) == true)
		{
			cells.emplace_back(cell);
		}
		cell = m_board->GetCellOnTheRight((*iterator)->GetCurrentCell());
		if (m_board->CanMoveToCell(cell) == true)
		{
			cells.emplace_back(cell);
		}

		iiii = rand() % 4;

		m_cell = cells.at(cells.size() - iiii % cells.size() - 1);
	}
}
