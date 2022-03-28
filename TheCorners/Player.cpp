#include "stdafx.h"
#include "Player.h"
#include "Figure.h"

Player::Player(): m_scale(1.0f), m_isActive(false)
{
	m_figures.reserve(9);
}

void Player::Init()
{
}

void Player::SetActive()
{
	m_isActive = true;
}

void Player::SetPassive()
{
	m_isActive = false;
}

bool Player::IsActive() const
{
	return m_isActive;
}

void Player::UnselectAllFigure()
{
	for (auto&& item : m_figures)
	{
		item->Unselect();
	}
}

std::vector<std::shared_ptr<Figure>> Player::GetFigures()
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

int Player::GetIndexSelectedFigure()
{
	int result = 0;

	const auto iterator = std::find_if(m_figures.begin(), m_figures.end(),
	                                   [](const auto& item) { return item->IsSelected(); });

	if (iterator != m_figures.end())
	{
		result = std::distance(m_figures.begin(), iterator);
	}

	return result;
}
