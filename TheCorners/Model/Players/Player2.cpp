#include "stdafx.h"
#include "Player2.h"

#include "PlayerBase.h"
#include "../Figure/FigureBase.h"

namespace Model
{
	Player2::~Player2()
	{
		m_figures.clear();
	}

	void Player2::Init()
	{
		m_figures.clear();
		for (int i = 1; i < 4; ++i)
		{
			for (int r = 8; r >= 6; --r)
			{
				m_figures.emplace_back(std::make_shared<FigureBase>());
				m_figures.back()->SetCurrentCell({i, r});
			}
		}
		m_selectFigure = m_figures.front();
	}
}
