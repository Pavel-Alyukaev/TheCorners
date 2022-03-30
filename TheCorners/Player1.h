// ****************************************************************************
//  Player1.h
//  TODO краткое описание класса
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
};
}
