#include "stdafx.h"
#include "GoalPlayer1.h"

#include "../../Interfaces/ISubjectView.h"

namespace Model
{
GoalPlayer1::GoalPlayer1()
= default;

GoalPlayer1::~GoalPlayer1()
= default;

void GoalPlayer1::Init()
{
	for (int i = 1; i < 4; ++i)
	{
		for (int r = 8; r >= 6; --r)
		{
			m_targetPosition.emplace_back( i,r );
		}
	}
}

void GoalPlayer1::NotifyAll()
{
	for (const auto& listener : m_listeners)
	{
		listener->UpdateFinishWindow(true);
	}
}

bool GoalPlayer1::Check(std::vector<std::shared_ptr<FigureBase>>& figures)
{
	bool result = GoalBaseGameCorners::Check(figures);
	if(result == true)
	{
		NotifyAll();
	}
	return result;
}
}
