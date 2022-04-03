// ****************************************************************************
//  ChessBoardView.h
//  Представление игрового поля
// ****************************************************************************

#pragma once
#include "../BaseView.h"
#include "../../Interfaces/IConverterCoordinateFromLocalToGlobal.h"

namespace View
{
	class ChessBoardView final : public BaseView, public IConverterCoordinateFromLocalToGlobal
	{
	public:
		ChessBoardView();

		/**
		* \brief Инициализация объекта
		*/
		void Init() override;

		/**
		* \brief Задать и обновить глобальную позицию представления
		* \param windowResolution 
		*/
		void CalculateAndSetGlobalPosition(sf::Vector2u windowResolution);

		// Реализация BaseView
		[[nodiscard]] sf::Vector2u GetSize() const override;

		// Реализация IConverterCoordinateFromLocalToGlobal
		[[nodiscard]] sf::Vector2f ConvertCellNumberToGlobalCoordinate(BoardCell currentCell) const override;

	private:
		sf::Texture m_boardTexture;
		sf::Vector2f m_globalPosition;

		sf::Vector2f m_firstCellLocalPosition;

		int m_cellSize;
	};
}
