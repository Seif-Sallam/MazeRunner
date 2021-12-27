#include "../headers/Player.h"
Player::Player()
    : m_Speed(250.f), m_Initialized(false)
{
    m_Animator = new Animator(this->m_Sprite);
    m_Elapsed = sf::seconds(0.f);
}

Player::~Player()
{
    delete m_Animator;
}

void Player::Init(MazeCell **&maze, int sizeX, int sizeY, int xPos, int yPos)
{
    x = xPos;
    y = yPos;
    m_Initialized = true;
    m_Maze = maze;
    m_SizeX = sizeX;
    m_SizeY = sizeY;

    Animation idle("IDLE");
    sf::Time delay = sf::seconds(1.f);
    idle.AddFrame(sf::IntRect(0, 0, 51, 44), delay);
    idle.Loop(true);
    m_Delay = sf::seconds(0.12f);
    m_Animator->AddAnimation(idle);
}

void Player::HandleEvents(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left && IsValidMove(LEFT) && m_Elapsed >= m_Delay)
    {
        m_Elapsed = sf::Time::Zero;
        SetPosition(--x, y);
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right && IsValidMove(RIGHT) && m_Elapsed >= m_Delay)
    {
        m_Elapsed = sf::Time::Zero;
        SetPosition(++x, y);
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && IsValidMove(UP) && m_Elapsed >= m_Delay)
    {
        m_Elapsed = sf::Time::Zero;
        SetPosition(x, --y);
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && IsValidMove(DOWN) && m_Elapsed >= m_Delay)
    {
        m_Elapsed = sf::Time::Zero;
        SetPosition(x, ++y);
    }
}

void Player::SetTextureAtles(const std::string &fileName)
{
    m_Texture.loadFromFile(fileName);
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setScale(0.5, 0.5);
}

void Player::Update(const sf::Time &deltaTime)
{
    if (m_Initialized)
    {
        m_Elapsed += deltaTime;
        m_Animator->SetCurrentAnimation("IDLE");
        HandleAnimations(deltaTime);
    }
}

sf::Vector2f Player::GetPosition()
{
    return m_Sprite.getPosition();
}

void Player::SetPosition(int x, int y)
{
    m_Sprite.setPosition(x * 32.0f, y * 32.0f);
}

void Player::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(m_Sprite);
}

void Player::HandleAnimations(const sf::Time &deltaTime)
{
    m_Animator->Update(deltaTime);
}

bool Player::IsValidMove(Direction move)
{
    if (m_Initialized)
        return !m_Maze[x][y].wall[int(move)];
    else
        return false;
}