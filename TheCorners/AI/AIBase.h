// ****************************************************************************
//  AIBase.h
//  Базовый класс для AI соперника
// ****************************************************************************

#pragma once
#include "../Model/Board/Board.h"

namespace Model
{
	class FigureBase;
}
namespace AI
{
class AIBase
	{
	public:
	
		std::shared_ptr<Model::FigureBase> GetFigure();
		BoardCell GetNewCell();

		void SetFigures(const std::vector<std::shared_ptr<Model::FigureBase>>& figures);
		void SetBoard(Model::Board* board);

		virtual void Calculate() = 0;

	protected:
		Model::Board* m_board;

		BoardCell m_cell;

		std::shared_ptr<Model::FigureBase> m_figure;

		std::vector<std::shared_ptr<Model::FigureBase>> m_figures;
	};
}