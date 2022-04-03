#include "stdafx.h"
#include "PlayerBase.h"

#include "../Figure/FigureBase.h"

namespace Model
{
class GoalBaseGameCorners;

PlayerBase::PlayerBase()
	{
		m_figures.reserve(9);
	}

	void PlayerBase::SetSelectFigure(std::shared_ptr<FigureBase> figure)
	{
		m_selectFigure = figure;
		m_selectFigure->NotifyAllState();
		m_selectFigure->NotifyAllNewPosition();
	}

	void PlayerBase::UpdateSelectFigure()
	{
		m_selectFigure->NotifyAllState();
		m_selectFigure->NotifyAllNewPosition();
	}

	std::shared_ptr<FigureBase> PlayerBase::GetSelectFigure()
	{
		return m_selectFigure;
	}

	std::vector<std::shared_ptr<FigureBase>> PlayerBase::GetFigures()
	{
		return m_figures;
	}

	std::shared_ptr<GoalBaseGameCorners> PlayerBase::GetGoal() const
	{
		return m_goal;
	}
}
