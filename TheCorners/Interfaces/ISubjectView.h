// ****************************************************************************
//  ISubjectView.h
//  Интерфейс слушателя (Субъект)
// ****************************************************************************

#pragma once

class ISubjectView
{
public:
	virtual ~ISubjectView() = default;
	virtual void UpdateFinishWindow(bool isSuccess) = 0;
	virtual void UpdateState() = 0;
	virtual void UpdatePosition(BoardCell position) = 0;
};
