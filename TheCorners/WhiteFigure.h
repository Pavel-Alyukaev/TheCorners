// ****************************************************************************
//  WhiteFigure.h
//	Класс белых фигур
// ****************************************************************************

#pragma once
#include "Figure.h"

class WhiteFigure final : public Figure
{
public:
	WhiteFigure();
	~WhiteFigure() override;

	void Init() override;
	
};
