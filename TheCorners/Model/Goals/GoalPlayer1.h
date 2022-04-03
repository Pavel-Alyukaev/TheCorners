// ****************************************************************************
//  GoalPlayer1.h
//  Цели игрока 2 
// ****************************************************************************

#pragma once
#include "GoalBaseGameCorners.h"
namespace Model
{
	class GoalPlayer1 final: public GoalBaseGameCorners
	{
	public:
		GoalPlayer1();
		~GoalPlayer1() override;

		void Init() override;
		bool Check(std::vector<std::shared_ptr<FigureBase>>& figures) override;

	protected:

		void NotifyAll() override;
	public:
	};
}
