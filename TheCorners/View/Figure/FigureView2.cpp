#include "stdafx.h"
#include "FigureView2.h"

namespace View
{
void FigureView2::Init()
{
	// Связываем текстуру и спрайт
	m_texture.loadFromFile("Resource/black.png");
	m_textureSelect.loadFromFile("Resource/black_select.png");
	m_Sprite.setTexture(m_texture);
}
}
