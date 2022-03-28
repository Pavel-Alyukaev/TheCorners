#include "stdafx.h"
#include "PlayerWite.h"
#include "Figure.h"
#include "WhiteFigure.h"

void PlayerWite::Init()
{
	m_figures.clear();
	for (int i = 1; i < 4; ++i)
	{
		for (int r = 8; r >= 6; --r)
		{
			m_figures.emplace_back(std::make_shared<WhiteFigure>());
			m_figures.back()->SetScale(m_scale);
			m_figures.back()->Init();
			m_figures.back()->SetCurrentCell({r, i});
		}
	}
	m_figures.front()->Select();
}
