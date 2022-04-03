#include "stdafx.h"
#include "GoalBaseGameCorners.h"

#include "../Figure/FigureBase.h"

namespace Model
{
GoalBaseGameCorners::GoalBaseGameCorners()
{
	//m_targetPosition.reserve(9);
}

bool GoalBaseGameCorners::Check(std::vector<std::shared_ptr<FigureBase>>& figures)
{
	bool result = true;
	for (auto element : figures)
	{
		const auto iterator = std::find_if(m_targetPosition.begin(), m_targetPosition.end(), [&](const BoardCell& item)
		{
			return element->GetCurrentCell() == item;
		});

		if (iterator == m_targetPosition.end())
		{
			result = false;
			break;
		}
	}

	return result;
}

void GoalBaseGameCorners::AddListener(ISubjectView* listener)
{
	m_listeners.emplace_back(listener);
}

void GoalBaseGameCorners::DeleteListener(ISubjectView* listener)
{
	m_listeners.erase(std::find(m_listeners.begin(), m_listeners.end(), listener));
}
}
