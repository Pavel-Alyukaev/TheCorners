// ****************************************************************************
//  ISubjectView.h
//  Интерфейс слушателя (Субъект)
// ****************************************************************************

#pragma once

class ISubjectView
{
public:
	virtual void UpdateState() = 0;
	virtual void UpdatePosition(BoardCell position) = 0;
};
