// ****************************************************************************
//  FiguresView.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
#include "..\..\ISubject.h"
namespace View
{
class ChessBoardView;
class FigureViewBase;

class FiguresView : public ISubjectView
{
public:

	FiguresView();
	void Init();

	std::vector<std::vector<std::shared_ptr<FigureViewBase>>> GetPlayerFiguresView();
	void UpdateState() override;
	void UpdatePosition(BoardCell position) override;


private:

	std::vector<std::vector<std::shared_ptr<FigureViewBase>>> m_playersFiguresView;



};
}
