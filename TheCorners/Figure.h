// ****************************************************************************
//  Figure.h
//  Базовый класс фигур
// ****************************************************************************

#pragma once
#include "IGameEntity.h"
#include "IMoveFigure.h"

class Figure : public IMoveFigure
{
public:
	Figure();
	virtual ~Figure();

	virtual void Init();

	BoardCell GetCurrentCell() const;
	void SetCurrentCell(BoardCell);

	void SetCurrentPosition(sf::Vector2f);

	void MovingForward() override;
	void MovingLeft() override;
	void MovingRight() override;
	void MovingBackward() override;
	void Stop();

	void Update(float elapsedTime);

	sf::Sprite GetSprite();

	void SetScale(float scale);
	void SetStep(float scale);

	void Select();
	void Unselect();
	bool IsSelected() const;
	bool IsMoved() const;

protected:
	// Объявляем объект Sprite
	sf::Sprite m_Sprite;

	// Добавляем текстуру
	sf::Texture m_Texture;
	sf::Texture m_TextureSelect;

	float m_scale;

	float m_step;

private:
	BoardCell m_currentCell;

	sf::Vector2f m_endPosition;
	sf::Vector2i m_direction;

	float m_Speed;
	float m_localMovedPosition;

	bool m_isMoved{};

	bool m_isSelected;
};
