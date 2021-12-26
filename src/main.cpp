#include "../headers/Application.h"

int main()
{
    Application app(sf::Vector2i(800, 600), "Maze Runner");
    app.Run();

    return 0;
}