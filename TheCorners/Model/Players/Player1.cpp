#include "stdafx.h"
#include "Player1.h"

#include "../Figure/FigureBase.h"

namespace Model
{
	Player1::~Player1()
	{
		m_figures.clear();
	}

	void Player1::Init()
	{
		m_figures.clear();
		for (int i = 1; i < 4; ++i)
		{
			for (int r = 8; r >= 6; --r)
			{
				m_figures.emplace_back(std::make_shared<FigureBase>());
				m_figures.back()->SetCurrentCell({r, i});
			}
		}
		m_selectFigure = m_figures.front();
	}

	void Player1::Restart()
	{
		int k = 0;
		for (int i = 1; i < 4; ++i)
		{
			for (int r = 8; r >= 6; --r)
			{
				m_figures[k++]->SetCurrentCell({r, i});
			}
		}
	}
}
