#include "stdafx.h"
#include "FigureBase.h"

#include "FigureViewBase.h"
namespace Model
{
FigureBase::FigureBase()
= default;

FigureBase::~FigureBase()
= default;

void FigureBase::MovingForward()
{
	m_currentCell.Row -= 1;
	NotifyAllNewPosition();
}

void FigureBase::MovingLeft()
{
	m_currentCell.Col -= 1;
	NotifyAllNewPosition();
}

void FigureBase::MovingRight()
{
	m_currentCell.Col += 1;
	NotifyAllNewPosition();
}

void FigureBase::MovingBackward()
{
	m_currentCell.Row += 1;
	NotifyAllNewPosition();
}

void FigureBase::AddListener(ISubjectView* listener)
{
	m_listeners.emplace_back(listener);
}

void FigureBase::DeleteListener(ISubjectView* listener)
{
	m_listeners.erase(std::find(m_listeners.begin(), m_listeners.end(), listener));
}

BoardCell FigureBase::GetCurrentCell() const
{
	return m_currentCell;
}

void FigureBase::SetCurrentCell(BoardCell position)
{
	m_currentCell = position;
	NotifyAllNewPosition();
}

void FigureBase::NotifyAllState()
{
	for (const auto& listener : m_listeners)
	{
		listener->UpdateState();
	}
}

void FigureBase::NotifyAllNewPosition()
{
	for (const auto& listener : m_listeners)
	{
		listener->UpdatePosition(m_currentCell);
	}
}
}
