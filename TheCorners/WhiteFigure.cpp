#include "stdafx.h"
#include "WhiteFigure.h"

WhiteFigure::WhiteFigure()
{
}

WhiteFigure::~WhiteFigure()
{
}

void WhiteFigure::Init()
{
	// Связываем текстуру и спрайт
	//TODO перенести в конфиг
	m_Texture.loadFromFile("wite.png");
	m_TextureSelect.loadFromFile("wite_select.png");
	m_Sprite.setTexture(m_Texture);

	m_Sprite.setScale(m_scale, m_scale);

	if (m_step == 0.0f)
	{
		m_step = m_Texture.getSize().x * m_scale;
	}
}
