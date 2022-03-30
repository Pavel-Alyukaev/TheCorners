#include "stdafx.h"
#include "PlayerBase.h"

#include "..\Figure\FigureBase.h"

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

void PlayerBase::ChangeSelectFigure(std::shared_ptr<FigureBase> figure)
{
	/*auto iterator = std::find_if(m_figures.begin(), m_figures.end(), [&](std::shared_ptr<FigureBase> item)
	{
		return item->GetCurrentCell() == m_selectFigure->GetCurrentCell();
	});

	do
	{
		if (++iterator == m_figures.end())
		{
			iterator = m_figures.begin();
		}

	} while (false);*/

	m_selectFigure = figure;
	m_selectFigure->NotifyAllState();
	m_selectFigure->NotifyAllNewPosition();
	
}

std::shared_ptr<FigureBase> PlayerBase::GetSelectFigure()
{
	return m_selectFigure;
}

std::vector<std::shared_ptr<FigureBase>> PlayerBase::GetFigure()
{
	return m_figures;
}
}
