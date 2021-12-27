#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "MazeGenerator.h"
#include "Player.h"
namespace state
{
    class LevelState : public State
    {
    public:
        LevelState();
        ~LevelState();
        void Update(const sf::Time &deltaTime) override;
        void Render(sf::RenderWindow &window) override;
        void HandleEvents(sf::Event &event) override;

    private:
        void ProcessInput(const sf::Time &deltaTime);

        sf::View m_View;
        const float m_ViewSpeed = 250.f;
        const int m_MazeSizeX, m_MazeSizeY;
        MazeCell **m_Maze;
        Player m_Player;
    };

}