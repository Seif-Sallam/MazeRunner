#include "../headers/Application.h"
#include "../headers/LevelState.h"
Application::Application(const sf::Vector2i &size, const std::string &title, bool fullscreen)
{
    if (!fullscreen)
        m_Window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title);
    else
        m_Window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), title, sf::Style::Fullscreen);
    m_View.setSize(m_Window->getSize().x, m_Window->getSize().y);
    m_View.setCenter(m_View.getSize() / 2.f);
    m_StateHandler = new state::StateHandler(m_CurrentState);
    m_CurrentState = m_StateHandler;
    m_StateHandler->RegisterState<state::LevelState>("LEVEL");
}

Application::~Application()
{
    delete m_Window;
}

void Application::Run()
{
    while (m_Window->isOpen())
    {
        float deltaTime = m_Clock.restart().asSeconds();
        EventHandler();
        Update(deltaTime);
        Render();
    }
}

void Application::Update(float deltaTime)
{
    m_CurrentState->Update(deltaTime);
}

void Application::EventHandler()
{
    sf::Event event;
    while (m_Window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
        {
            m_Window->close();
        }
        else if (event.type == sf::Event::Resized)
        {
            m_View.setSize(m_Window->getSize().x, m_Window->getSize().y);
        }
        m_CurrentState->HandleEvents(event);
    }
}

void Application::Render()
{
    m_Window->clear();
    m_Window->setView(m_View);
    m_CurrentState->Render(*m_Window);
    m_Window->display();
}