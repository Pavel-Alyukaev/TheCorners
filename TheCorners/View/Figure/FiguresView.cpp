#include "stdafx.h"
#include "FiguresView.h"

#include "FigureView1.h"
#include "FigureView2.h"

namespace View
{
	FiguresView::FiguresView()
	{
		m_playersFiguresView.reserve(2);
	}

	void FiguresView::Init()
	{
		std::vector<std::shared_ptr<FigureViewBase>> m_figureView1;
		std::vector<std::shared_ptr<FigureViewBase>> m_figureView2;

		for (int i = 0; i < 9; ++i)
		{
			m_figureView1.emplace_back(std::make_shared<FigureView1>());
			m_figureView1.back()->Init();
			m_figureView2.emplace_back(std::make_shared<FigureView2>());
			m_figureView2.back()->Init();
		}
		m_playersFiguresView.emplace_back(m_figureView1);
		m_playersFiguresView.emplace_back(m_figureView2);
	}

	std::vector<std::vector<std::shared_ptr<FigureViewBase>>> FiguresView::GetPlayerFiguresView()
	{
		return m_playersFiguresView;
	}

	void FiguresView::UpdateState()
	{
		for (const auto& element : m_playersFiguresView)
		{
			for (const auto& item : element)
			{
				item->Unselect();
			}
		}
	}

	void FiguresView::UpdatePosition(BoardCell position)
	{
	}
}
