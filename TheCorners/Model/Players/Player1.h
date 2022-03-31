// ****************************************************************************
//  Player1.h
//  Класс игрока
// ****************************************************************************

#pragma once
#include "PlayerBase.h"

namespace Model
{
	class Player1 final : public PlayerBase
	{
	public:
		~Player1() override;
		void Init() override;
		void Restart() override;
	};
}
