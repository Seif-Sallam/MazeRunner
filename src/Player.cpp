#include "../headers/Player.h"
Player::Player()
    : m_Speed(250.f)
{
    m_Animator = new Animator(this->m_Sprite);
}

Player::~Player()
{
}

void Player::HandleEvents(sf::Event &event)
{
}

void Player::SetTextureAtles(const std::string &fileName)
{
    m_Texture.loadFromFile(fileName);
    m_Sprite.setTexture(m_Texture);
}

void Player::Update(const sf::Time &deltaTime)
{
    // this->m_Animator->SetCurrentAnimation("IDLE");
    HandleAnimations(deltaTime);
    float dt = deltaTime.asSeconds();
    // Move the player without any constraints
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_Sprite.move(-m_Speed * dt, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_Sprite.move(m_Speed * dt, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        m_Sprite.move(0.f, -m_Speed * dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        m_Sprite.move(0.f, m_Speed * dt);
}

sf::Vector2f Player::GetPosition()
{
    return m_Sprite.getPosition();
}

void Player::SetPosition(const sf::Vector2f &position)
{
    m_Sprite.setPosition(position);
}

void Player::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(m_Sprite);
}

void Player::HandleAnimations(const sf::Time &deltaTime)
{

    // m_Animator->Update(deltaTime);

    // m_Sprite.setTextureRect(sf::IntRect(m_Sprite.getPosition().x, m_Sprite.getPosition().y, 32, 32));
}

void Player::AddAnimation(Animation &anim)
{
    // m_Animator->AddAnimation(anim.GetName(), anim);
}