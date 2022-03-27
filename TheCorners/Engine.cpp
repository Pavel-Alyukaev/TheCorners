#include "stdafx.h"
#include "Engine.h"
#include "Figure.h"


Engine::Engine() : m_isFirstPress(sf::Keyboard::Key::Unknown, true)
{
}


void Engine::Init()
{
    m_isFirstPress = std::pair<sf::Keyboard::Key, bool>(sf::Keyboard::Key::Unknown, true);

    // Получаем разрешение экрана, создаем окно SFML и View
    sf::Vector2u resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    m_Window.create(sf::VideoMode(resolution.x, resolution.y),
                    "Simple Game Engine",
                    sf::Style::Fullscreen);

    m_chessBoard.Init();
    auto aa = m_chessBoard.GetSize();

    float scale = 0.9f * resolution.y / aa.y;

    m_chessBoard.SetScale(scale);
    m_chessBoard.UpdateScale();

    player.SetScale(scale);
    player.Init();

    for (auto&& item : player.GetFigure())
    {
        item->SetStep(m_chessBoard.GetCellSize());
        item->SetCurrentPossition(m_chessBoard.ConvertCageNumberToGlobalCoordinate(item->GetCurrentCell()));

        m_chessBoard.ChangeOcupateCells(item->GetCurrentCell());
    }

    SelectNextFigure();

}


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

void Engine::Events()
{
    sf::Event event{};

	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Resized:
				{
                sf::IntRect visibleAria(0,0,event.size.width,event.size.height);
                m_Window.setView(sf::View(static_cast<sf::FloatRect>(visibleAria)));
                break;
				}
            default: break;
		}
	}
}

void Engine::Input()
{
	const auto activeFigur = player.GetFigure();
	int selectIndex = player.GetindexSelectedFigure();

    if (KeyPress(sf::Keyboard::Escape))
    {
        m_Window.close();
    }
    else if (KeyPress(sf::Keyboard::W))
    {
        auto newCell = m_chessBoard.GetCellFromTheTop(activeFigur[selectIndex]->GetCurrentCell());
        if (m_chessBoard.CanMoveToCell(newCell))
        {
            activeFigur[selectIndex]->SetCurrentCell(newCell);
            m_chessBoard.ChangeOcupateCells(newCell);
            activeFigur[selectIndex]->MovingForward();
        }
    }
    else if (KeyPress(sf::Keyboard::D))
    {
	    const auto newCell = m_chessBoard.GetCellOnTheRight(activeFigur[player.GetindexSelectedFigure()]->GetCurrentCell());
        if (m_chessBoard.CanMoveToCell(newCell))
        {
            activeFigur[selectIndex]->SetCurrentCell(newCell);
            m_chessBoard.ChangeOcupateCells(newCell);
        	activeFigur[selectIndex]->MovingRight();
        }
    }
    else if (KeyPress(sf::Keyboard::S))
    {
	    const auto newCell = m_chessBoard.GetCellFromTheBottom(activeFigur[player.GetindexSelectedFigure()]->GetCurrentCell());
        if (m_chessBoard.CanMoveToCell(newCell))
        {
            activeFigur[selectIndex]->SetCurrentCell(newCell);
            m_chessBoard.ChangeOcupateCells(newCell);
            activeFigur[selectIndex]->MovingBackward();
        }
    }
    else if (KeyPress(sf::Keyboard::A))
    {
	    const auto newCell = m_chessBoard.GetCellOnTheLeft(activeFigur[player.GetindexSelectedFigure()]->GetCurrentCell());
        if (m_chessBoard.CanMoveToCell(newCell))
        {
            activeFigur[selectIndex]->SetCurrentCell(newCell);
            m_chessBoard.ChangeOcupateCells(newCell);
            activeFigur[selectIndex]->MovingLeft();
        }
    }
    else if (KeyPress(sf::Keyboard::Up))
    {
        SelectNextFigure();

    }
}

void Engine::SelectNextFigure()
{
    const auto activeFigur = player.GetFigure();
    int selectIndex = player.GetindexSelectedFigure();
    do
    {
        if (selectIndex < activeFigur.size() - 1)
            selectIndex++;
        else
            selectIndex = 0;
    } while (!m_chessBoard.ThereAreMoves(activeFigur[selectIndex]->GetCurrentCell()));
    player.UnselectAllFigure();
    activeFigur[selectIndex]->Select();

}

void Engine::Update(float dtAsSeconds)
{
	for (const auto& item : player.GetFigure())
	{
        item->Update(dtAsSeconds);
	}
}

void Engine::Draw()
{
    // Стираем предыдущий кадр
    m_Window.clear(sf::Color::White);

    // Отрисовываем фон
    m_Window.draw(m_BackgroundSprite);

    // И Боба
    m_Window.draw(m_chessBoard.GetSprite());

    for (const auto& item : player.GetFigure())
    {
        m_Window.draw(item->GetSprite());
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
	if(m_isFirstPress.first != key && m_isFirstPress.second == true && sf::Keyboard::isKeyPressed(key) )
	{
        m_isFirstPress.first = key;
        m_isFirstPress.second = false;
        result = true;
	}
    else if(m_isFirstPress.first == key && m_isFirstPress.second == false && sf::Keyboard::isKeyPressed(key) == false)
    {
        m_isFirstPress.first = sf::Keyboard::Key::Unknown;
        m_isFirstPress.second = true;
    }
    return result;
}
