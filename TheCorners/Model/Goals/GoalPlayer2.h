// ****************************************************************************
//  GoalPlayer2.h
//  Цели игрока 2 
// ****************************************************************************

#pragma once
#include "GoalBaseGameCorners.h"
namespace Model
{
	class GoalPlayer2 final: public GoalBaseGameCorners
	{
	public:
		~GoalPlayer2() override;

		void Init() override;

		bool Check(std::vector<std::shared_ptr<FigureBase>>& figures) override;

	private:
		void NotifyAll() override;
	};
}
