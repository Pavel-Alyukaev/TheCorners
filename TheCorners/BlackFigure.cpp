#include "stdafx.h"
#include "BlackFigure.h"

void BlackFigure::Init()
{
	// Связываем текстуру и спрайт
	//TODO убрать в конфиг название текстуры
	m_Texture.loadFromFile("black.png");
	m_TextureSelect.loadFromFile("black_select.png");
	m_Sprite.setTexture(m_Texture);

	m_Sprite.setScale(m_scale, m_scale);

	if (m_step == 0.0f)
	{
		m_step = m_Texture.getSize().x * m_scale;
	}
}
