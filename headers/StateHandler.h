#pragma once
#include "State.h"
#include <functional>
#include <string>
#include <vector>
namespace state
{
    class StateHandler : public State
    {
    public:
        StateHandler(State *&currentState);
        ~StateHandler();
        void Update(const sf::Time &deltaTime) override;
        void Render(sf::RenderWindow &window) override;

        template <class T>
        void RegisterState(const std::string &name)
        {
            m_States.push_back(std::make_pair(name, []()
                                              { return new T(); }));
        }

    private:
        std::vector<std::pair<std::string, std::function<State *()>>> m_States;
        State *&m_CurrentState;
    };
}