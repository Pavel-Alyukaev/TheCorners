// ****************************************************************************
//  ISubject.h
//  Интерфейс слушателя (Субъект)
// ****************************************************************************

#pragma once

class ISubjectView;
class IListener
{
public:
	virtual ~IListener() = default;
	virtual void AddListener(ISubjectView*) = 0;
	virtual void DeleteListener(ISubjectView*) = 0;

private:
	virtual void NotifyAllState() = 0;
	virtual void NotifyAllNewPosition() = 0;
};
