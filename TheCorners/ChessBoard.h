// ****************************************************************************
//  ChessBoard.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

#include <unordered_set>
#include <SFML/Graphics.hpp>

struct BoardCell;

enum class Direction
{
	forward,
	backward,
	left,
	right,

	none

};

class ChessBoard
{
public:
	ChessBoard();
	void Init();

	sf::Vector2f ConvertCageNumberToGlobalCoordinate(BoardCell) const;

	BoardCell GetCellOnTheRight(BoardCell currCell)const;
	BoardCell GetCellFromTheTop(BoardCell currCell)const;
	BoardCell GetCellOnTheLeft(BoardCell currCell)const;
	BoardCell GetCellFromTheBottom(BoardCell currCell)const;

	void SetScale(float scale);
	void UpdateScale();
	sf::Vector2u GetSize() const;

	sf::Sprite GetSprite();
	int GetCellSize() const;

	bool CheckBorder(BoardCell currCell) const;

	bool ThereAreMoves(BoardCell currCell) const;

	void ChangeOcupateCells(BoardCell currCell);
	bool CanMoveToCell(BoardCell currCell) const;


private:

	// Объявляем объект Sprite
	sf::Sprite m_Sprite;

	// Добавляем текстуру
	sf::Texture m_Texture;

	float m_scale;

	int m_cellSize;

	sf::Vector2f m_firstCellLocalPossition;
	sf::Vector2u m_resolution;

	sf::Vector2f m_globalPossition;

	std::vector<BoardCell> m_occupiedCells;

};
