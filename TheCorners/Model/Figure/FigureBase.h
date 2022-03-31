// ****************************************************************************
//  FigureBase.h
//  Класс фигуры
// ****************************************************************************

#pragma once
#include <list>

#include "../../Interfaces/IListener.h"
#include "../../Interfaces/IMoveFigure.h"
class ISubjectView;

namespace View
{
	class FigureViewBase;
}

namespace Model
{
	class FigureBase final : public IMoveFigure, IListener
	{
	public:
		FigureBase();
		~FigureBase() override;

		void MovingForward() override;
		void MovingLeft() override;
		void MovingRight() override;
		void MovingBackward() override;
		void AddListener(ISubjectView*) override;
		void DeleteListener(ISubjectView*) override;

		BoardCell GetCurrentCell() const;
		void SetCurrentCell(BoardCell);

		void NotifyAllState() override;
		void NotifyAllNewPosition() override;
	
	protected:
		BoardCell m_currentCell;

		sf::Vector2f m_endPosition;
		sf::Vector2i m_direction;

		float m_Speed;
		float m_localMovedPosition;

		bool m_isMoved{};

		bool m_isSelected;

		std::list<ISubjectView*> m_listeners;
	};
}
