#include "stdafx.h"
#include "FinishWindows.h"

#include "FailedWindow.h"
#include "SuccessWindow.h"


namespace View
{
FinishWindows::FinishWindows()
{
	m_finishWindows.try_emplace(ResultWindow::Success, new SuccessWindow());
	m_finishWindows.try_emplace(ResultWindow::Failure, new FailedWindow());
}

void FinishWindows::InitAll() const
{
	for (auto&& item : m_finishWindows)
	{
		item.second->Init();
	}
}

BaseWindow* FinishWindows::GetWindow(ResultWindow result) const
{
	return m_finishWindows.at(result);
}

BaseWindow* FinishWindows::GetActiveWindow()
{
	BaseWindow* result = nullptr;

	const auto iterator = std::find_if(m_finishWindows.begin(), m_finishWindows.end(),
	                                   [](const auto& item) { return item.second->IsVisible(); });

	if (iterator != m_finishWindows.end())
	{
		result = iterator->second;
	}

	return result;
}

void FinishWindows::SetResolution(sf::Vector2u resolution) const
{
	for (auto&& element : m_finishWindows)
	{
		element.second->CalculateAndSetGlobalPosition(resolution);
	}
}

void FinishWindows::SetScale(float scale) const
{
	for (auto&& element : m_finishWindows)
	{
		element.second->SetScale(scale);
	}
}
}
