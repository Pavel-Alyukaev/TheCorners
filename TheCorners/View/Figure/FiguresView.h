// ****************************************************************************
//  FiguresView.h
//  Представление всех фигур
// ****************************************************************************

#pragma once
#include "../../Interfaces/ISubjectView.h"

namespace View
{
	class ChessBoardView;
	class FigureViewBase;

	class FiguresView final : public ISubjectView
	{
	public:
		FiguresView();
		void Init();

		/**
		* \brief Получить все фигуры всех играков
		* \return все фигуры по игракам
		*/
		std::vector<std::vector<std::shared_ptr<FigureViewBase>>> GetPlayerFiguresView();

		// Реализация ISubjectView
		void UpdateState() override;
		void UpdatePosition(BoardCell position) override;
		//------------------------

	private:
		std::vector<std::vector<std::shared_ptr<FigureViewBase>>> m_playersFiguresView;
	};
}
