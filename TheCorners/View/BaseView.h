// ****************************************************************************
//  BaseView.h
//  Базовый класс представлений
// ****************************************************************************

#pragma once
namespace View
{
	class BaseView
	{
	public:
		BaseView();

		virtual ~BaseView() = default;

		virtual void Init() = 0;

		/**
		* \brief Получение размеров исходного представления без изменения масштаба
		* \return Ветор с размерами
		*/
		virtual sf::Vector2u GetSize() const = 0;

		/**
		* \brief Задать маштаб всем представлениям
		* \param scale - масштаб
		*/
		void SetScale(float scale);

		/**
		* \brief 
		* \return 
		*/
		sf::Sprite GetSprite();

	protected:
		float m_scale; // Объявляем масштаб

		sf::Sprite m_Sprite{}; // Объявляем объект Sprite
	};
}
