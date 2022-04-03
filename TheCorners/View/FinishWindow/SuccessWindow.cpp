#include "stdafx.h"
#include "SuccessWindow.h"

namespace View
{

void SuccessWindow::Init()
{
	// Связываем текстуру и спрайт
	m_texture.loadFromFile("Resource/Win.png");
	m_Sprite.setTexture(m_texture);
}

void SuccessWindow::UpdateFinishWindow(bool isSuccess)
{
	if(isSuccess == true)
	{
		Show();
	}
}
}
