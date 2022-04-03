// ****************************************************************************
//  GoalsBase.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

namespace Model
{
class FigureBase;
}
class IGoalsBase
{
public:
	virtual ~IGoalsBase() = default;
	virtual	void Init() = 0;
	virtual bool Check(std::vector<std::shared_ptr<Model::FigureBase>>& figures) = 0;

};
