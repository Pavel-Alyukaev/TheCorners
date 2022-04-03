// ****************************************************************************
//  BaseWindow.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
#include "../../Interfaces/IFinishWindow.h"
#include "../../Interfaces/ISubjectView.h"
#include "../BaseView.h"

namespace View
{
	class BaseWindow : public BaseView, public IFinishWindow, public ISubjectView
	{
	public:
		BaseWindow();

		void Show() override;
		void Hide() override;
		[[nodiscard]] sf::Vector2u GetSize() const override;
		bool IsVisible() override;

		void CalculateAndSetGlobalPosition(sf::Vector2u windowResolution);

		void Update(float dtAsSeconds);

		void UpdateState() override{}
		void UpdatePosition(BoardCell position) override{}


	protected:
		sf::Texture m_texture;

		float m_newScale;

		sf::Vector2f m_globalPosition;
		bool m_isVisible;
	};
}
