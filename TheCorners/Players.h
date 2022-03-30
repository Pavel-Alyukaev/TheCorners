// ****************************************************************************
//  Players.h
//  TODO краткое описание класса
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

	void InitAll();

	std::shared_ptr<PlayerBase> GetActivePlayer();

	void ChangeActivePlayer();

	std::vector<std::shared_ptr<PlayerBase>> GetPlayers();

	void UpdateFigurePosition();

private:
	std::vector<std::shared_ptr<PlayerBase>> m_players;
	std::shared_ptr<PlayerBase> m_activePlayer;
};
}
