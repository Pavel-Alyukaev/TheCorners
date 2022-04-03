// ****************************************************************************
//  IFinishWindow.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

class IFinishWindow
{
public:
	virtual ~IFinishWindow() = default;

	virtual void Show() = 0;

	virtual void Hide() = 0;

	virtual bool IsVisible() = 0;

	
};
