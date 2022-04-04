// ****************************************************************************
//  Engine.h
//  Класс игрового движка
// ****************************************************************************
#pragma once
#include "Model/Board/Board.h"
#include "Model/Players/Players.h"
#include "View/ChessBoard/ChessBoardView.h"
#include "View/Figure/FiguresView.h"
#include "View/FinishWindow/FinishWindows.h"
#include "AI/AIBase.h"

class Engine
{
public:
	// Конструктор движка
	Engine();
	void Init();
	~Engine();

	// Функция старт вызовет все приватные функции
	void Start();

private:
	void Input();
	void Restart();
	void Events();
	void ChangeSelection(std::shared_ptr<Model::PlayerBase>);
	void RestartGame();
	void Update(float dtAsSeconds);
	void Draw();

	void MovingFigureByPlayer(BoardCell newCell);

	bool KeyPress(sf::Keyboard::Key key);


	sf::RenderWindow m_Window;

	View::ChessBoardView m_chessBoardView;
	View::FiguresView m_figuresView;
	View::FinishWindows m_finishWindows;

	
	Model::Board m_chessBoard;
	Model::Players m_players;

	AI::AIBase* m_ai;

	std::pair<sf::Keyboard::Key, bool> m_isFirstPress;
};
