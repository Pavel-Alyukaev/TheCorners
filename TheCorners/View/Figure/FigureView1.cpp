#include "stdafx.h"
#include "FigureView1.h"

namespace View
{
void FigureView1::Init()
{
	// Связываем текстуру и спрайт
	m_texture.loadFromFile("Resource/wite.png");
	m_textureSelect.loadFromFile("Resource/wite_select.png");
	m_Sprite.setTexture(m_texture);
}
}
