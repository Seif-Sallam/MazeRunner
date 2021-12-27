#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Animator.h"

class Player : public sf::Drawable
{
public:
    Player();
    ~Player();
    void HandleEvents(sf::Event &event);
    void SetTextureAtles(const std::string &fileName);
    void Update(const sf::Time &deltaTime);
    sf::Vector2f GetPosition();
    void SetPosition(const sf::Vector2f &position);
    void AddAnimation(Animation &anim);
    void draw(sf::RenderTarget &window, sf::RenderStates state = sf::RenderStates::Default) const override;

private:
    void HandleAnimations(const sf::Time &deltaTime);

    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
    float m_Speed;
    Animator *m_Animator;
};