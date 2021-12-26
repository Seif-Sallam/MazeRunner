#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::View view;
    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
            if (event.type == sf::Event::Resized)
            {
                view.setSize(window.getSize().x, window.getSize().y);
            }
        }

        window.clear();
        window.setView(view);
        window.display();
    }

    return 0;
}