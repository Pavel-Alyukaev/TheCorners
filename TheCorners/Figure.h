// ****************************************************************************
//  Figure.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
#include "IGameEntity.h"
#include "IMoveFigure.h"

class Figure : public IMoveFigure
{
public:
	Figure();
	~Figure() = default;

	void Init();


	BoardCell GetCurrentCell();
	void SetCurrentCell(BoardCell);

	void SetCurrentPossition(sf::Vector2f);

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
	bool IsSelected();

private:

	BoardCell m_currentCell;

	sf::Vector2f m_endPosition;
	sf::Vector2i m_direction;

	float m_Speed;
	float m_localMovedPosition;

	bool m_isMoved{};

	// Объявляем объект Sprite
	sf::Sprite m_Sprite;

	// Добавляем текстуру
	sf::Texture m_Texture;
	sf::Texture m_TextureSelect;

	float m_scale;

	float m_step;

	bool m_isSelected;
};
