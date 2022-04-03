// ****************************************************************************
//  GoalBaseGameCorners.h
//  Базовый класс целей игроков
// ****************************************************************************

#pragma once
#include <list>

#include "../../Interfaces/IGoalsBase.h"
#include "../../Interfaces/IListener.h"

namespace Model
{
	class GoalBaseGameCorners : public IGoalsBase, public IListener
	{
	public:
		GoalBaseGameCorners();

		/**
		 * \brief Проверка на достижение цели
		 * \param figures Список фигур тгрока
		 * \return Флаг достигнута или нет цель
		 */

		void AddListener(ISubjectView*) override;
		void DeleteListener(ISubjectView*) override;

	private:
		void NotifyAllState() override{}
		void NotifyAllNewPosition() override{}
	protected:

		std::vector<BoardCell> m_targetPosition{};
		std::list<ISubjectView*> m_listeners;

	};
}