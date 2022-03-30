#include "stdafx.h"
#include "Engine.h"

#include "Model\Figure\FigureBase.h"
#include "View\Figure\FigureView1.h"
#include "View\Figure\FigureView2.h"
#include "Model\Players\PlayerBase.h"
#include "PlayerBlack.h"

class Textures;
/**
 * \brief Конструктор
 */
Engine::Engine() : m_isFirstPress(sf::Keyboard::Key::Unknown, true)
{
}

/**
 * \brief Инициализация  игрового движка
 */
void Engine::Init()
{
	m_isFirstPress = std::pair(sf::Keyboard::Key::Unknown, true);

	// Получаем разрешение экрана, создаем окно SFML и View
	sf::Vector2u resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	m_Window.create(sf::VideoMode(resolution.x, resolution.y),
	                "Simple Game Engine",
	                sf::Style::Fullscreen);

	m_players.InitAll();
	
	m_chessBoardView.Init();
	const auto chessBoardSize = m_chessBoardView.GetSize();

	const float scale = 0.9f * static_cast<float>(resolution.y) / static_cast<float>(chessBoardSize.y);

	m_chessBoardView.SetScale(scale);
	m_chessBoardView.UpdateScale(resolution);

	m_figuresView.Init();


	
	for (const auto& element : m_figuresView.GetPlayerFiguresView())
	{
		for (const auto& item : element)
		{
			item->SetBoard(&m_chessBoardView);
			item->SetScale(scale);
		}
	}

	// Подписываемся нак события изменения селекта
	for (int i = 0; i < 2; ++i)
	{
		auto figureView = m_figuresView.GetPlayerFiguresView()[i];
		auto figureModel = m_players.GetPlayers()[i]->GetFigure();

		for (int j = 0; j < 9; ++j)
		{
			//figureModel[j]->AddListener(&m_figuresView);
			figureModel[j]->AddListener(figureView[j].get());
		}
	}

	m_players.UpdateFigurePosition();

	for (const auto& player : m_players.GetPlayers())
	{
		for (const auto& item : player->GetFigure())
		{
			m_chessBoard.ChangeOccupiedCell(item->GetCurrentCell(), item->GetCurrentCell());
		}
	}
	//players.emplace_back(new PlayerWite());
	//players.emplace_back(new PlayerBlack());
	//players.front()->SetActive();

	//for (auto&& player : players)
	//{
	//	player->SetScale(scale);
	//	player->Init();

	//	for (auto&& item : player->GetFigures())
	//	{
	//		item->SetStep(static_cast<float>(m_chessBoard.GetCellSize()));
	//		item->SetCurrentPosition(m_chessBoard.ConvertCageNumberToGlobalCoordinate(item->GetCurrentCell()));

	//		m_chessBoard.ChangeOcupateCells(item->GetCurrentCell());
	//	}
	//}

	//SelectNextFigure();
}

Engine::~Engine()
{
}

/**
 * \brief Запуск симуляции
 */
void Engine::Start()
{
	// Расчет времени
	sf::Clock clock;

	while (m_Window.isOpen())
	{
		// Перезапускаем таймер и записываем отмеренное время в dt
		sf::Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		Input();
		Events();
		Update(dtAsSeconds);
		Draw();
	}
}

/**
 * \brief Метод получения активного игрока
 * \return - указатель на активного игрока
 */
//Player* Engine::GetActivePlayer() const
//{
//	Player* result = nullptr;
//
//	const auto iterator = std::find_if(players.begin(), players.end(), [](Player* item) { return item->IsActive(); });
//	if (iterator != players.end())
//	{
//		result = *iterator;
//	}
//	return result;
//}

/**
 * \brief Метод переключения активного игрока
 */
//void Engine::ChangeActivePlayer()
//{
//	//auto iterator = std::find_if(players.begin(), players.end(), [](const auto item) { return item->IsActive(); });
//
//	//(*iterator)->SetPassive();
//	//if (++iterator == players.end())
//	//{
//	//	(*players.begin())->SetActive();
//	//}
//	//else
//	//{
//	//	(*iterator)->SetActive();
//	//}
//}

/**
 * \brief Метод обработки событий
 */
void Engine::Events()
{
	sf::Event event{};

	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Resized:
				{
					sf::IntRect visibleAria(0, 0, event.size.width, event.size.height);
					m_Window.setView(sf::View(static_cast<sf::FloatRect>(visibleAria)));
					break;
				}
			default: break;
		}
	}
}

/**
 * \brief Метод обработки input-a
 */
void Engine::Input()
{
	if (KeyPress(sf::Keyboard::Escape))
	{
		m_Window.close();
	}
	else if (KeyPress(sf::Keyboard::W))
	{
		const auto activeFigure = m_players.GetActivePlayer()->GetSelectFigure();
		const auto newCell = m_chessBoard.GetCellFromTheTop(activeFigure->GetCurrentCell());
		if (m_chessBoard.CanMoveToCell(newCell))
		{
			m_chessBoard.ChangeOccupiedCell(activeFigure->GetCurrentCell(), newCell);
			activeFigure->SetCurrentCell(newCell);
			m_players.ChangeActivePlayer();

			//activeFigure->MovingForward();
		}
	}
	/*else if (KeyPress(sf::Keyboard::D) && activeFigure->IsMoved() == false)
	{
		const auto newCell = m_chessBoard.GetCellOnTheRight(
			activeFigures[GetActivePlayer()->GetIndexSelectedFigure()]->GetCurrentCell());
		if (m_chessBoard.CanMoveToCell(newCell))
		{
			activeFigure->SetCurrentCell(newCell);
			m_chessBoard.ChangeOcupateCells(newCell);
			ChangeActivePlayer();
			SelectNextFigure();
			activeFigure->MovingRight();
		}
	}
	else if (KeyPress(sf::Keyboard::S) && activeFigure->IsMoved() == false)
	{
		const auto newCell = m_chessBoard.GetCellFromTheBottom(
			activeFigures[GetActivePlayer()->GetIndexSelectedFigure()]->GetCurrentCell());
		if (m_chessBoard.CanMoveToCell(newCell))
		{
			activeFigure->SetCurrentCell(newCell);
			m_chessBoard.ChangeOcupateCells(newCell);
			ChangeActivePlayer();
			SelectNextFigure();
			activeFigure->MovingBackward();
		}
	}
	else if (KeyPress(sf::Keyboard::A) && activeFigure->IsMoved() == false)
	{
		const auto newCell = m_chessBoard.GetCellOnTheLeft(
			activeFigures[GetActivePlayer()->GetIndexSelectedFigure()]->GetCurrentCell());
		if (m_chessBoard.CanMoveToCell(newCell))
		{
			activeFigure->SetCurrentCell(newCell);
			m_chessBoard.ChangeOcupateCells(newCell);
			ChangeActivePlayer();
			SelectNextFigure();
			activeFigure->MovingLeft();
		}
	}*/
	else if (KeyPress(sf::Keyboard::Up))
	{

		auto bb = m_players.GetActivePlayer()->GetFigure();
		auto aa = m_players.GetActivePlayer()->GetSelectFigure();

		auto iterator = std::find_if(bb.begin(), bb.end(), [&](const auto& item)
			{
				return item->GetCurrentCell() == aa->GetCurrentCell();
			});

		do
		{
			if (++iterator == bb.end())
			{
				iterator = bb.begin();
			}
		} while (m_chessBoard.ThereAreMoves((*iterator)->GetCurrentCell()) == false);
		

		m_players.GetActivePlayer()->ChangeSelectFigure(*iterator);
	}
}


/**
 * \brief Мметод обновления положения всех объектов
 * \param dtAsSeconds - время кадра
 */
void Engine::Update(float dtAsSeconds)
{
	sf::Vector2f local;
		for (const auto& element : m_figuresView.GetPlayerFiguresView())
		{
			for (auto item : element)
			{
				 local = item->GetLocalCoordinateToMove(dtAsSeconds);
				
				//auto qq = m_chessBoardView.ConvertCageNumberToGlobalCoordinate(item->GetCurrentPosition());

				//auto newPosition = qq + local;

				//item->GetSprite().setPosition(newPosition);
			}
		}
	}


/**
 * \brief  Мметод перерисовки всех объектов
 */
void Engine::Draw()
{
	// Стираем предыдущий кадр
	m_Window.clear(sf::Color::White);

	// Отрисовываем фон
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Sprite);

	// Отрисовываем доску
	m_Window.draw(m_chessBoardView.GetSprite());

	// Отрисовываем фигуры всех игроков на доске
	for (const auto& element : m_figuresView.GetPlayerFiguresView())
	{
		for (auto item : element)
		{
			m_Window.draw(item->GetSprite());
		}
	}

	// Отображаем все, что нарисовали
	m_Window.display();
}


/**
 * \brief Метод определяющий была нажата клавиша один раз
 * \param key клавиша
 * \return флаг
 */
bool Engine::KeyPress(sf::Keyboard::Key key)
{
	bool result = false;
	if (m_isFirstPress.first != key && m_isFirstPress.second == true && sf::Keyboard::isKeyPressed(key))
	{
		m_isFirstPress.first = key;
		m_isFirstPress.second = false;
		result = true;
	}
	else if (m_isFirstPress.first == key && m_isFirstPress.second == false && sf::Keyboard::isKeyPressed(key) == false)
	{
		m_isFirstPress.first = sf::Keyboard::Key::Unknown;
		m_isFirstPress.second = true;
	}

	return result;
}
