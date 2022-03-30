// ****************************************************************************
//  BaseView.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
namespace View
{
class BaseView
{
public:
	virtual ~BaseView() = default;
	void SetScale(float scale);
	virtual sf::Vector2u GetSize() const = 0;

	sf::Sprite GetSprite();

protected:
	float m_scale;

	// Объявляем объект Sprite
	sf::Sprite m_Sprite;
};
}
