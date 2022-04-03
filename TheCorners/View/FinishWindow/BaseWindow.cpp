#include "stdafx.h"
#include "BaseWindow.h"

#include <iostream>

namespace View
{
BaseWindow::BaseWindow(): m_isVisible(false)
{
}

void BaseWindow::Show()
{
	m_isVisible = true;
	m_newScale = m_scale / 2.0f;
}

void BaseWindow::Hide()
{
	m_isVisible = false;
}


bool BaseWindow::IsVisible()
{
	return m_isVisible;
}

sf::Vector2u BaseWindow::GetSize() const
{
	return m_texture.getSize();
}

void BaseWindow::CalculateAndSetGlobalPosition(sf::Vector2u windowResolution)
{
	m_globalPosition = (static_cast<sf::Vector2f>(windowResolution) -
		static_cast<sf::Vector2f>(m_texture.getSize()) * m_scale / 2.0f) / 2.0f;


	m_Sprite.setScale(m_scale / 2.0f, m_scale / 2.0f);

	m_Sprite.setPosition(m_globalPosition);
	std::cout << m_globalPosition.x <<"  " << m_globalPosition.y << std::endl;

}

void BaseWindow::Update(float dtAsSeconds)
{
	m_newScale += dtAsSeconds;

	const float scale = std::clamp(m_newScale, m_scale / 2.0f, m_scale);
	if (std::abs(scale - (m_scale / 2.0f)) < 0.01);
	{
		const sf::Vector2f newPosition = m_globalPosition - std::abs(scale - m_scale/2.0f)/2.0f * static_cast<sf::Vector2f>(m_texture.getSize());

		std::cout << newPosition.x << "  " << newPosition.y << std::endl;
		m_Sprite.setScale(scale, scale);
	}
}
}
