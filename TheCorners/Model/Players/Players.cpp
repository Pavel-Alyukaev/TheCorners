#include "stdafx.h"
#include "Players.h"

#include "Player1.h"
#include "Player2.h"
#include "../Figure/FigureBase.h"


namespace Model
{
	Players::Players()
	{
		m_players.emplace_back(std::make_shared<Player1>());
		m_players.emplace_back(std::make_shared<Player2>());

		m_activePlayer = m_players.front();
	}

	Players::~Players()
	= default;

	void Players::InitAll() const
	{
		for (auto&& item : m_players)
		{
			item->Init();
		}
	}

	std::shared_ptr<PlayerBase> Players::GetActivePlayer()
	{
		return m_activePlayer;
	}

	void Players::ChangeActivePlayer()
	{
		auto iterator = std::find(m_players.begin(), m_players.end(), m_activePlayer);

		if (++iterator == m_players.end())
		{
			m_activePlayer = m_players.front();
		}
		else
		{
			m_activePlayer = *iterator;
		}

		m_activePlayer->UpdateSelectFigure();
	}

	std::vector<std::shared_ptr<PlayerBase>> Players::GetPlayers()
	{
		return m_players;
	}

	void Players::UpdateFigurePosition() const
	{
		for (auto&& player : m_players)
		{
			for (const auto& item : player->GetFigures())
			{
				item->NotifyAllNewPosition();
			}
		}
	}

	void Players::Restart()
	{
		m_activePlayer.reset();
		for (auto player : m_players)
		{
			player->Restart();
			player->SetSelectFigure(player->GetFigures().front());
		}
		m_activePlayer = m_players.front();
	}
}
