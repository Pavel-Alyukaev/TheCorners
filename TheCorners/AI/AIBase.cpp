#include "stdafx.h"
#include "AIBase.h"

namespace Model
{
class FigureBase;
}
namespace AI
{
	std::shared_ptr<Model::FigureBase> AIBase::GetFigure()
	{
		return m_figure;
	}

	BoardCell AIBase::GetNewCell()
	{
		return m_cell;
	}

	void AIBase::SetFigures(const std::vector<std::shared_ptr<Model::FigureBase>>& figures)
	{
		m_figures = figures;
	}

	void AIBase::SetBoard(Model::Board* board)
	{
		m_board = board;
	}
}
