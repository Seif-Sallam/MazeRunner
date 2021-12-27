#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Animator.h"
#include "MazeGenerator.h"

class Player : public sf::Drawable
{
public:
    Player();
    ~Player();
    void Init(MazeCell **&maze, int sizeX, int sizeY, int xPos, int yPos);
    void HandleEvents(sf::Event &event);
    void SetTextureAtles(const std::string &fileName);
    void Update(const sf::Time &deltaTime);
    sf::Vector2f GetPosition();
    void SetPosition(int x, int y);
    void draw(sf::RenderTarget &window, sf::RenderStates state = sf::RenderStates::Default) const override;
    bool IsValidMove(Direction move);

private:
    void HandleAnimations(const sf::Time &deltaTime);

    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
    float m_Speed;
    Animator *m_Animator;
    int m_SizeX, m_SizeY;
    MazeCell **m_Maze;
    int x, y;
    bool m_Initialized;
    sf::Time m_Elapsed, m_Delay;
};