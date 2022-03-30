// ****************************************************************************
//  ChessBoardView.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
#include "..\BaseView.h"

namespace View
{
class ChessBoardView final : public BaseView
{
public:
	ChessBoardView();
	void Init();
	sf::Vector2u GetSize() const override;
	sf::Vector2f GetGlobalCoordinate() const;
	void UpdateScale(sf::Vector2u);
	sf::Vector2f ConvertCageNumberToGlobalCoordinate(BoardCell currentCell) const;

private:
	sf::Texture m_boardTexture;
	sf::Vector2f m_globalPosition;

	sf::Vector2f m_firstCellLocalPosition;

	int m_cellSize;
};
}
