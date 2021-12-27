#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

namespace state
{
    class State
    {
    public:
        State() {}
        virtual ~State() {}
        virtual void Update(const sf::Time &deltaTime) {}
        virtual void Render(sf::RenderWindow &window) {}
        virtual void HandleEvents(sf::Event &event) {}
    };

    // class StateMenu : public State
    // {
    // public:
    //     StateMenu();
    //     ~StateMenu();
    // };
}