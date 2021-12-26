#include "../headers/LevelState.h"
#include <ctime>
namespace state
{
    LevelState::LevelState()
        : m_MazeSizeX(15), m_MazeSizeY(10)
    {
        m_View.setCenter(sf::Vector2f(0.f, 0.f));
        m_Maze = GenerateMaze(m_MazeSizeX, m_MazeSizeY, 0, 0, (unsigned int)time(0));
    }

    LevelState::~LevelState()
    {
    }

    void LevelState::Update(float deltaTime)
    {
        ProcessInput(deltaTime);
    }

    void LevelState::Render(sf::RenderWindow &window)
    {
        m_View.setSize(window.getSize().x, window.getSize().y);
        window.setView(m_View);
        sf::RectangleShape borders[4];
        borders[UP].setSize(sf::Vector2f(30.f, 2.0f));
        borders[DOWN].setSize(sf::Vector2f(30.f, 2.0f));
        borders[RIGHT].setSize(sf::Vector2f(2.0f, 30.f));
        borders[LEFT].setSize(sf::Vector2f(2.0f, 30.f));
        sf::RectangleShape BOX(sf::Vector2f(30.0f, 30.0f));
        int count = 0;

        for (int i = 0; i < m_MazeSizeX; i++)
        {
            for (int j = 0; j < m_MazeSizeY; j++)
            {
                borders[UP].setPosition(i * 32.0f, j * 32.0f);
                borders[DOWN].setPosition(i * 32.0f, j * 32.0f + 30.0f);
                borders[RIGHT].setPosition(i * 32.0f + 30.0f, j * 32.0f);
                borders[LEFT].setPosition(i * 32.0f, j * 32.0f);
                BOX.setPosition(i * 32.0f, j * 32.0f);
                for (int k = 0; k < 4; k++)
                {
                    if (m_Maze[i][j].wall[k] == true)
                        borders[k].setFillColor(sf::Color::Blue);
                    else
                    {
                        borders[k].setFillColor(sf::Color::White);
                    }
                    window.draw(borders[k]);
                    window.draw(BOX);
                }
            }
        }
    }

    void LevelState::HandleEvents(sf::Event &event)
    {
    }

    void LevelState::ProcessInput(float deltaTime)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            m_View.move(m_ViewSpeed * deltaTime, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            m_View.move(-m_ViewSpeed * deltaTime, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            m_View.move(0.0f, -m_ViewSpeed * deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            m_View.move(0.0f, m_ViewSpeed * deltaTime);
    }

}