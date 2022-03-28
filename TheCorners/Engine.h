// ****************************************************************************
//  Engine.h
//  Класс игрового движка
// ****************************************************************************
#pragma once
#include "ChessBoard.h"
#include "Player.h"

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
	sf::RenderWindow m_Window;


	std::vector<Player*> players;
	Player* GetActivePlayer() const;
	void ChangeActivePlayer();

	ChessBoard m_chessBoard;

	// Объявляем спрайт и текстуру для фона
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	void Input();
	void SelectNextFigure();
	void Events();
	void Update(float dtAsSeconds);
	void Draw();

	bool KeyPress(sf::Keyboard::Key key);
	std::pair<sf::Keyboard::Key, bool> m_isFirstPress;
};
