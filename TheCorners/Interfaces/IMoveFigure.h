// ****************************************************************************
//  IMoveFigure.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

class IMoveFigure
{
public:
	virtual ~IMoveFigure() = default;
	virtual void MovingForward() = 0;
	virtual void MovingLeft() = 0;
	virtual void MovingRight() = 0;
	virtual void MovingBackward() = 0;
};
