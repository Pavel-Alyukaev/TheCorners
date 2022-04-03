#include "stdafx.h"
#include "FailedWindow.h"

namespace View
{

void FailedWindow::Init()
{
	// Связываем текстуру и спрайт
	m_texture.loadFromFile("Resource/Loser.png");
	m_Sprite.setTexture(m_texture);
}

void FailedWindow::UpdateFinishWindow(bool isSuccess)
{
	if(isSuccess == false)
	{
		Show();
	}
}
}
