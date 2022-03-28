#include "stdafx.h"
#include "PlayerBlack.h"
#include "BlackFigure.h"
#include "Figure.h"

void PlayerBlack::Init()
{
	m_figures.clear();
	for (int i = 1; i < 4; ++i)
	{
		for (int r = 8; r >= 6; --r)
		{
			m_figures.emplace_back(std::make_shared<BlackFigure>());
			m_figures.back()->SetScale(m_scale);
			m_figures.back()->Init();
			m_figures.back()->SetCurrentCell({i, r});
		}
	}
	m_figures.front()->Select();
}
