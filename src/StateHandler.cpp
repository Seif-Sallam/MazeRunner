#include "../headers/StateHandler.h"

namespace state
{
    StateHandler::StateHandler(State *&currentState)
        : m_CurrentState(currentState)
    {
    }

    StateHandler::~StateHandler()
    {
    }

    void StateHandler::Update(const sf::Time &deltaTime)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            //just to make it work right now
            m_CurrentState = m_States.back().second();
        }
    }

    void StateHandler::Render(sf::RenderWindow &window)
    {
        sf::RectangleShape shape(sf::Vector2f(120.0f, 120.0f));
        shape.setPosition(sf::Vector2f(160.0f, 420.0f));
        shape.setFillColor(sf::Color::Green);
        window.draw(shape);
    }

}