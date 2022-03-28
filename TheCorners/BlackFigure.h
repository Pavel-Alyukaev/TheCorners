// ****************************************************************************
//  BlackFigure.h
//  Класс черных фигур
// ****************************************************************************

#pragma once
#include "Figure.h"

class BlackFigure final : public Figure
{
public:
	BlackFigure() = default;
	~BlackFigure() override = default;

	void Init() override;
};
