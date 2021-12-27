#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "StateHandler.h"
class Application
{
public:
    Application(const sf::Vector2i &size, const std::string &title, bool fullscreen = false);
    ~Application();

    void Run();

private:
    void EventHandler();
    void Update(const sf::Time &deltaTime);
    void Render();

private:
    sf::RenderWindow *m_Window;
    sf::View m_View;
    sf::Clock m_Clock;
    state::State *m_CurrentState;
    state::StateHandler *m_StateHandler;
};