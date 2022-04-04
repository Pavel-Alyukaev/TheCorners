// ****************************************************************************
//  PlayerBase.h
//  Базовый класс игроков
// ****************************************************************************

#pragma once

namespace Model
{
class GoalBaseGameCorners;
class FigureBase;

	class PlayerBase
	{
	public:
		PlayerBase();

		virtual ~PlayerBase() = default;

		/**
		* \brief Инициализация игрока
		*/
		virtual void Init() = 0;

		/**
		* \brief Задать выбранную фигуру
		* \param figure - Указатель на фигуру
		*/
		void SetSelectFigure(std::shared_ptr<FigureBase> figure);

		/**
		* \brief Обновить выбранную фигуру
		*/
		void UpdateSelectFigure();

		/**
		* \brief Получить выбранную фигуру
		* \return Указатель на фигуру
		*/
		std::shared_ptr<FigureBase> GetSelectFigure();

		/**
		* \brief Получить все фигуры игрока
		* \return Вектор фигур
		*/
		std::vector<std::shared_ptr<FigureBase>> GetFigures();

		[[nodiscard]] std::shared_ptr<GoalBaseGameCorners> GetGoal() const;

		virtual void Restart() = 0;

	protected:
		std::vector<std::shared_ptr<FigureBase>> m_figures;

		std::shared_ptr<FigureBase> m_selectFigure;

		std::shared_ptr <GoalBaseGameCorners> m_goal;
	};
}
