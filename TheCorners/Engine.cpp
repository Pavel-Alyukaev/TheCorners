#include "stdafx.h"
#include "Engine.h"

#include "Model/Figure/FigureBase.h"
#include "Model/Goals/GoalBaseGameCorners.h"
#include "Model/Players/PlayerBase.h"
#include "View/Figure/FigureView1.h"
#include "View/Figure/FigureView2.h"

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
	m_chessBoardView.CalculateAndSetGlobalPosition(resolution);

	// Инициализируем финишные окна
	m_finishWindows.InitAll();
	m_finishWindows.SetScale(scale);
	m_finishWindows.SetResolution(resolution);

	// Инициализируем графику фигур
	m_figuresView.Init();
	for (const auto& element : m_figuresView.GetPlayerFiguresView())
	{
		for (const auto& item : element)
		{
			item->SetConverter(&m_chessBoardView);
			item->SetScale(scale);
			item->CalculateStep();
		}
	}

	// Подписываемся на события изменения селекта
	for (int i = 0; i < 2; ++i)
	{
		auto figureView = m_figuresView.GetPlayerFiguresView()[i];
		auto figureModel = m_players.GetPlayers()[i]->GetFigures();

		for (int j = 0; j < 9; ++j)
		{
			figureModel[j]->AddListener(&m_figuresView);
			figureModel[j]->AddListener(figureView[j].get());
		}
	}

	m_players.GetPlayers()[0]->GetGoal()->AddListener(m_finishWindows.GetWindow(View::ResultWindow::Success));
	m_players.GetPlayers()[0]->GetGoal()->AddListener(m_finishWindows.GetWindow(View::ResultWindow::Failure));
	m_players.GetPlayers()[1]->GetGoal()->AddListener(m_finishWindows.GetWindow(View::ResultWindow::Success));
	m_players.GetPlayers()[1]->GetGoal()->AddListener(m_finishWindows.GetWindow(View::ResultWindow::Failure));

	m_players.UpdateFigurePosition();

	// Вычисляем какие клетки заняты
	for (const auto& player : m_players.GetPlayers())
	{
		for (const auto& item : player->GetFigures())
		{
			m_chessBoard.ChangeOccupiedCell(item->GetCurrentCell(), item->GetCurrentCell());
		}
	}

	// Вычисляем начальные выбранные фигуры  
	for (const auto& player : m_players.GetPlayers())
	{
		for (auto element : player->GetFigures())
		{
			if (m_chessBoard.ThereAreMoves(element->GetCurrentCell()) == true)
			{
				player->SetSelectFigure(element);
				break;
			}
		}
	}
	m_players.GetActivePlayer()->UpdateSelectFigure();
}

Engine::~Engine()
= default;

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
 * \brief Метод обработки событий
 */
void Engine::Events()
{
	sf::Event event{};

	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Resized :
			{
				sf::IntRect visibleAria(0, 0, event.size.width, event.size.height);
				m_Window.setView(sf::View(static_cast<sf::FloatRect>(visibleAria)));
				break;
			}
		default : break;
		}
	}
}

void Engine::ChangeSelection(const std::shared_ptr<Model::PlayerBase> player)
{
	auto figures = player->GetFigures();
	const auto selectFigure = player->GetSelectFigure();

	auto iterator = std::find_if(figures.begin(), figures.end(), [&](const auto& item)
	{
		return item->GetCurrentCell() == selectFigure->GetCurrentCell();
	});

	do
	{
		if (++iterator == figures.end())
		{
			iterator = figures.begin();
		}
	}
	while (m_chessBoard.ThereAreMoves((*iterator)->GetCurrentCell()) == false);

	player->SetSelectFigure(*iterator);
}

void Engine::RestartGame()
{
	m_players.Restart();
	m_chessBoard.Deinit();

	// Вычисляем какие клетки заняты
	for (const auto& player : m_players.GetPlayers())
	{
		for (const auto& item : player->GetFigures())
		{
			m_chessBoard.ChangeOccupiedCell(item->GetCurrentCell(), item->GetCurrentCell());
		}

		ChangeSelection(player);
	}
	m_players.GetActivePlayer()->UpdateSelectFigure();
}

void Engine::MovingFigureByPlayer(const BoardCell newCell)
{
	const auto activeFigure = m_players.GetActivePlayer()->GetSelectFigure();
	auto figures = m_players.GetActivePlayer()->GetFigures();

	if (m_chessBoard.CanMoveToCell(newCell))
	{
		m_chessBoard.ChangeOccupiedCell(activeFigure->GetCurrentCell(), newCell);
		activeFigure->SetCurrentCell(newCell);
		m_players.GetActivePlayer()->GetGoal()->Check(figures);
		m_players.ChangeActivePlayer();
	}
}

/**
 * \brief Метод обработки input-a
 */
void Engine::Input()
{
	if (KeyPress(sf::Keyboard::Escape))
	{
		auto window = m_finishWindows.GetActiveWindow();
		if(window !=nullptr)
		{
			window->Hide();
			RestartGame();
		}
		else
		{
			m_Window.close();
		}
	}
	else if (KeyPress(sf::Keyboard::W))
	{
		const auto activeFigure = m_players.GetActivePlayer()->GetSelectFigure();
		const auto newCell = m_chessBoard.GetCellFromTheTop(activeFigure->GetCurrentCell());
		MovingFigureByPlayer(newCell);
	}
	else if (KeyPress(sf::Keyboard::D))
	{
		const auto activeFigure = m_players.GetActivePlayer()->GetSelectFigure();
		const auto newCell = m_chessBoard.GetCellOnTheRight(activeFigure->GetCurrentCell());
		MovingFigureByPlayer(newCell);
	}
	else if (KeyPress(sf::Keyboard::S))
	{
		const auto activeFigure = m_players.GetActivePlayer()->GetSelectFigure();
		const auto newCell = m_chessBoard.GetCellFromTheBottom(activeFigure->GetCurrentCell());
		MovingFigureByPlayer(newCell);
	}
	else if (KeyPress(sf::Keyboard::A))
	{
		const auto activeFigure = m_players.GetActivePlayer()->GetSelectFigure();
		const auto newCell = m_chessBoard.GetCellOnTheLeft(activeFigure->GetCurrentCell());
		MovingFigureByPlayer(newCell);
	}
	else if (KeyPress(sf::Keyboard::Up))
	{
		ChangeSelection(m_players.GetActivePlayer());
	}
	else if (KeyPress(sf::Keyboard::R))
	{
		RestartGame();
	}
	else if (KeyPress(sf::Keyboard::F))
	{
		m_finishWindows.GetWindow(View::ResultWindow::Success)->Hide();
		m_finishWindows.GetWindow(View::ResultWindow::Failure)->Show();
	}
	else if (KeyPress(sf::Keyboard::G))
	{
		m_finishWindows.GetWindow(View::ResultWindow::Failure)->Hide();
		m_finishWindows.GetWindow(View::ResultWindow::Success)->Show();
	}
}

void Engine::Restart()
{
	m_players.Restart();
}

/**
 * \brief Мметод обновления положения всех объектов
 * \param dtAsSeconds - время кадра
 */
void Engine::Update(float dtAsSeconds)
{
	for (const auto& element : m_figuresView.GetPlayerFiguresView())
	{
		for (auto item : element)
		{
			item->Update(dtAsSeconds);
		}
	}

	if (m_finishWindows.GetActiveWindow() != nullptr)
	{
		m_finishWindows.GetActiveWindow()->Update(dtAsSeconds);
	}
}

/**
 * \brief  Мметод перерисовки всех объектов
 */
void Engine::Draw()
{
	// Стираем предыдущий кадр
	m_Window.clear(sf::Color::White);

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

	if(m_finishWindows.GetActiveWindow() != nullptr)
	{
		m_Window.draw(m_finishWindows.GetActiveWindow()->GetSprite());
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
