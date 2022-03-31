// ****************************************************************************
//  Player2.h
//	Класс игрока
// ****************************************************************************

#pragma once
#include "PlayerBase.h"

namespace Model
{
	class Player2 final : public PlayerBase
	{
	public:
		~Player2() override;
		void Init() override;
	};
}
