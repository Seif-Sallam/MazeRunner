#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation();
    Animation(const std::string &name);
    Animation(Animation &a);
    Animation(const Animation &a);
    void AddFrame(const sf::IntRect &rect, sf::Time delay);
    void SetName(const std::string &name);
    void Play();
    void Stop();
    void Loop(bool value = true);
    void Reset();
    sf::IntRect Update(const sf::Time &deltaTime);
    std::string GetName();

private:
    struct Frame
    {
        Frame(const sf::IntRect &bounds, sf::Time delay)
            : bounds(bounds), delay(delay)
        {
        }
        sf::IntRect bounds;
        sf::Time delay;
    };
    std::string m_Name;
    std::vector<Frame> m_Frames;
    bool m_Loop;
    bool m_Play;
    sf::Clock m_Timer;
    sf::Time m_OverlappedTime;
    int32_t m_FramePointer;
};