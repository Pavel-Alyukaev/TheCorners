// ****************************************************************************
//  Players.h
//  Класс хранящий информацию о игроках
// ****************************************************************************

#pragma once
namespace Model
{
	class PlayerBase;

	class Players
	{
	public:
		Players();
		~Players();

		/**
		* \brief Инициализация игроков
		*/
		void InitAll() const;

		/**
		* \brief Получить активного игрока
		* \return Указатель на активного игрока
		*/
		std::shared_ptr<PlayerBase> GetActivePlayer();

		/**
		* \brief Сменить активного игрока
		*/
		void ChangeActivePlayer();

		/**
		* \brief Получить всех игроков
		* \return Вектор игроков
		*/
		std::vector<std::shared_ptr<PlayerBase>> GetPlayers();

		/**
		* \brief Обновление позиции фигуры (используется для растановки фигур вначале игры)
		*/
		void UpdateFigurePosition() const;

	private:
		std::vector<std::shared_ptr<PlayerBase>> m_players;
		std::shared_ptr<PlayerBase> m_activePlayer;
	};
}
