#include "stdafx.h"
#include "GoalPlayer2.h"

#include "../../Interfaces/ISubjectView.h"
namespace Model
{
GoalPlayer2::~GoalPlayer2()
= default;

void GoalPlayer2::Init()
{
	for (int i = 1; i < 4; ++i)
	{
		for (int r = 8; r >= 6; --r)
		{
			m_targetPosition.emplace_back( r, i );
		}
	}
}

void GoalPlayer2::NotifyAll()
{
	for (const auto& listener : m_listeners)
	{
		listener->UpdateFinishWindow(false);
	}
}

bool GoalPlayer2::Check(std::vector<std::shared_ptr<FigureBase>>& figures)
{
	bool result = GoalBaseGameCorners::Check(figures);
	if (result == true)
	{
		NotifyAll();
	}
	return result;
}
}
