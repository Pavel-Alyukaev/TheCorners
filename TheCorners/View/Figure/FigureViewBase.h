// ****************************************************************************
//  FigureViewBase.h
//  Базовое представление фирур
// ****************************************************************************

#pragma once
#include "../BaseView.h"
#include "../../Interfaces/ISubjectView.h"

class IConverterCoordinateFromLocalToGlobal;

namespace View
{
	class ChessBoardView;

	class FigureViewBase : public BaseView, public ISubjectView
	{
	public:
		FigureViewBase();

		/**
		* \brief Смена текстуры на "выбрано"
		*/
		void Select();

		/**
		* \brief Смена текстуры на "невыбрано"
		*/
		void Unselect();

		/**
		* \brief Задать конвертер координат
		*/
		void SetConverter(IConverterCoordinateFromLocalToGlobal*);

		/**
		* \brief обнавление анимации
		* \param elapsedTime - время кадра
		*/
		void Update(float elapsedTime);

		/**
		* \brief Получить текущую позицию в координатах игрового поля
		* \return 
		*/
		[[nodiscard]] BoardCell GetCurrentPosition() const;

		/**
		* \brief Вычисление размера шага
		*/
		void CalculateStep();

		// Реализация ISubjectView
		[[nodiscard]] sf::Vector2u GetSize() const override;
		//-------------------------

		// Реализация ISubjectView
		void UpdateState() override;
		void UpdatePosition(BoardCell position) override;
		void UpdateFinishWindow(bool isSuccess) override {}
		//-------------------------


	protected:
		sf::Texture m_texture;
		sf::Texture m_textureSelect;

		BoardCell m_currentPosition;
		BoardCell m_endPosition;
		bool m_isSelected;
		IConverterCoordinateFromLocalToGlobal* m_board;

		float m_localMovedPosition;

		float m_speed;

		float m_step;

		bool m_isMoved;

		sf::Vector2f m_direction;
		sf::Vector2f m_localCoordinate;
		sf::Vector2f m_globalCoordinate;
	};
}
