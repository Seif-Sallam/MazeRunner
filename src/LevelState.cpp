#include "../headers/LevelState.h"
#include <ctime>
namespace state
{
    LevelState::LevelState()
        : m_MazeSizeX(15), m_MazeSizeY(10)
    {
        m_View.setCenter(sf::Vector2f(0.f, 0.f));
        m_Maze = GenerateMaze(m_MazeSizeX, m_MazeSizeY, 0, 0, (unsigned int)time(0));
        m_Player.SetPosition(sf::Vector2f(0.f, 0.f));
        m_Player.SetTextureAtles("rsc/Player.png");
        Animation anim("IDLE");
        sf::Time delay = sf::seconds(1.f);

        anim.AddFrame(sf::IntRect(0, 0, 51, 44), delay);
        anim.Loop(true);
        m_Player.AddAnimation(anim);
    }

    LevelState::~LevelState()
    {
    }

    void LevelState::Update(const sf::Time &deltaTime)
    {
        ProcessInput(deltaTime);
        m_Player.Update(deltaTime);
    }

    void LevelState::Render(sf::RenderWindow &window)
    {
        m_View.setSize(window.getSize().x, window.getSize().y);
        window.setView(m_View);
        sf::RectangleShape borders[4];
        borders[UP].setSize(sf::Vector2f(32.f, 2.0f));
        borders[DOWN].setSize(sf::Vector2f(32.f, 2.0f));
        borders[RIGHT].setSize(sf::Vector2f(2.0f, 32.f));
        borders[LEFT].setSize(sf::Vector2f(2.0f, 32.f));
        sf::RectangleShape BOX(sf::Vector2f(32.0f, 32.0f));
        int count = 0;

        for (int i = 0; i < m_MazeSizeX; i++)
        {
            for (int j = 0; j < m_MazeSizeY; j++)
            {
                borders[UP].setPosition(i * 32.0f, j * 32.0f);
                borders[DOWN].setPosition(i * 32.0f, j * 32.0f + 32.0f);
                borders[RIGHT].setPosition(i * 32.0f + 32.0f, j * 32.0f);
                borders[LEFT].setPosition(i * 32.0f, j * 32.0f);
                if (i == 0)
                    borders[LEFT].move(sf::Vector2f(0.0f, -1.0f));

                if (j == 0)
                    borders[UP].move(sf::Vector2f(-1.0f, 0.f));
                BOX.setPosition(i * 32.0f, j * 32.0f);
                window.draw(BOX);
                for (int k = 0; k < 4; k++)
                {
                    if (m_Maze[i][j].wall[k] == true)
                        borders[k].setFillColor(sf::Color::Blue);
                    else
                        borders[k].setFillColor(sf::Color::White);
                    window.draw(borders[k]);
                }
            }
        }

        window.draw(m_Player);
    }

    void LevelState::HandleEvents(sf::Event &event)
    {
        m_Player.HandleEvents(event);
    }

    void LevelState::ProcessInput(const sf::Time &deltaTime)
    {
        float dt = deltaTime.asSeconds();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            m_View.move(m_ViewSpeed * dt, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            m_View.move(-m_ViewSpeed * dt, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            m_View.move(0.0f, -m_ViewSpeed * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            m_View.move(0.0f, m_ViewSpeed * dt);
    }

}