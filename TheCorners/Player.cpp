#include "stdafx.h"
#include "Player.h"

#include "Figure.h"

Player::Player(): m_isActive(false), m_scale(1.0f)
{
	m_figures.reserve(9);
}

void Player::Init()
{
	m_figures.clear();
	for (int i = 1; i < 4; ++i)
	{
		for (int r = 8; r >= 6; --r)
		{
			m_figures.emplace_back(std::make_shared<Figure>());
			m_figures.back()->SetScale(m_scale);
			m_figures.back()->Init();
			m_figures.back()->SetCurrentCell({ r,i });
			
		}
	}
	m_figures.front()->Select();

}

void Player::SetActive()
{
	m_isActive = true;
}

void Player::SetPassive()
{
	m_isActive = false;
}

void Player::UnselectAllFigure()
{
	for (auto&& item : m_figures)
	{
		item->Unselect();
	}
}

std::vector<std::shared_ptr<Figure>> Player::GetFigure()
{
	return m_figures;
}

void Player::Update(float dtAsSeconds)
{
	for (auto&& item : m_figures)
	{
		item->Update(dtAsSeconds);
	}
}

void Player::SetScale(float scale)
{
	m_scale = scale;
}

int Player::GetindexSelectedFigure()
{
	int result = -1;

	const auto iterator = std::find_if(m_figures.begin(), m_figures.end(), [](const auto& item) {return item->IsSelected(); });

	if(iterator != m_figures.end())
	{
		result = iterator - m_figures.begin();
	}

	return result;
}
