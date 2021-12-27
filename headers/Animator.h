#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include "Animation.h"

class Animator
{
public:
    Animator(sf::Sprite &parentSprite);
    void SetCurrentAnimation(const std::string &name);
    void AddAnimation(const std::string &name, Animation &animation);
    void Update(const sf::Time &deltaTime);

private:
    std::unordered_map<std::string, Animation> m_Animations;
    sf::Sprite &m_Sprite;
    Animation *m_ActiveAnimation;
    Animation *m_LastAnimation;
};