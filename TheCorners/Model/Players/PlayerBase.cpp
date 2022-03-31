#include "stdafx.h"
#include "PlayerBase.h"

#include "../Figure/FigureBase.h"

namespace Model
{
	PlayerBase::PlayerBase()
	{
		m_figures.reserve(9);
	}

	void PlayerBase::MovingForward()
	{
		m_selectFigure->MovingForward();
	}

	void PlayerBase::MovingLeft()
	{
		m_selectFigure->MovingLeft();
	}

	void PlayerBase::MovingRight()
	{
		m_selectFigure->MovingRight();
	}

	void PlayerBase::MovingBackward()
	{
		m_selectFigure->MovingBackward();
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
}
