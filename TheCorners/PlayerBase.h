// ****************************************************************************
//  PlayerBase.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once


namespace Model
{
class FigureBase;

class PlayerBase
{
public:
	PlayerBase();

	virtual ~PlayerBase() = default;

	virtual void Init() = 0;

	void MovingForward();
	void MovingLeft();
	void MovingRight();
	void MovingBackward();

	void ChangeSelectFigure();

	std::vector<std::shared_ptr<FigureBase>> GetFigure();  

protected:
	std::vector<std::shared_ptr<FigureBase>> m_figures;

	std::shared_ptr<FigureBase> m_selectFigure;
};
}
