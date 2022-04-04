// ****************************************************************************
//  FinishWindows.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

#include "BaseWindow.h"

namespace View
{
enum class ResultWindow
{
	Success,
	Failure
};

	class FinishWindows
	{
	public:
		FinishWindows();
		void InitAll() const;

		[[nodiscard]] BaseWindow* GetWindow(ResultWindow result) const;
		BaseWindow* GetActiveWindow();

		void SetResolution(sf::Vector2u resolution) const;

		void SetScale(float scale) const;
	private:
		std::unordered_map<ResultWindow, BaseWindow*> m_finishWindows;
	};
}
