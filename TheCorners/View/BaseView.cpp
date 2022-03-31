#include "stdafx.h"
#include "BaseView.h"
namespace View
{
BaseView::BaseView(): m_scale(1.0f)
{
}

void BaseView::SetScale(float scale)
{
	m_scale = scale;
	m_Sprite.setScale(scale, scale);
}

sf::Sprite BaseView::GetSprite()
{
	return m_Sprite;
}
}
