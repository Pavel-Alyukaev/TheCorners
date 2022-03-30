// ****************************************************************************
//  FigureViewBase.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
#include "..\BaseView.h"
#include "..\..\ISubject.h"
namespace View
{
class ChessBoardView;
class FigureViewBase : public BaseView, public ISubjectView
{
public:

	FigureViewBase();

	virtual void Init();

	void Select();

	void Unselect();

	void MoveTo(sf::Vector2f);

	sf::Vector2u GetSize() const override;

	void UpdateState() override;
	void UpdatePosition(BoardCell position) override;

	void SetBoard(ChessBoardView*);
	sf::Vector2f GetLocalCoordinateToMove(float elapsedTime);

	void SetGlobalCoordinate();

	BoardCell GetCurrentPosition() const;

protected:
	sf::Texture m_texture;
	sf::Texture m_textureSelect;

	BoardCell m_currentPosition;
	BoardCell m_endPosition;
	bool m_isSelected;
	ChessBoardView* m_board;

	float m_localMovedPosition;

	float m_Speed;

	float m_step;

	bool m_isMoved;

	sf::Vector2f m_direction;
	sf::Vector2f m_localCoordinate;
	sf::Vector2f m_globalCoordinate;
};
}
