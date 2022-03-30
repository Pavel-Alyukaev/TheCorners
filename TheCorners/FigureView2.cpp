#include "stdafx.h"
#include "FigureView2.h"

namespace View
{
void FigureView2::Init()
{
	// Связываем текстуру и спрайт
	m_texture.loadFromFile("black.png");
	m_textureSelect.loadFromFile("black_select.png");
	m_Sprite.setTexture(m_texture);
}

}
