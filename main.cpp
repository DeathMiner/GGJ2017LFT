#include <SFML/Graphics.hpp>
#include "engine.hpp"

int grid_x = 1280 / 64;
int grid_y = 720 / 64;
char grid[11][21] = {
    "00000000000000000000",
    "00000000000000000000",
    "00000000000000000000",
    "00000000000000000000",
    "00000000000000000000",
    "00000000000000000000",
    "00000000000000110000",
    "00000000000000000000",
    "00010010000010010011",
    "00110011000110010001",
    "11110011111111111111"
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML GGJ2017LFT!", sf::Style::Close | sf::Style::Titlebar);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    int x, y;

    sf::RectangleShape rectangle(sf::Vector2f(64, 64));

    Player my_player;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if (event.key.code == sf::Keyboard::Left)
                    my_player.setPos(sf::Vector2i(my_player.getPos().x - 1, my_player.getPos().y));
                else if (event.key.code == sf::Keyboard::Right)
                    my_player.setPos(sf::Vector2i(my_player.getPos().x + 1, my_player.getPos().y));
                else if (event.key.code == sf::Keyboard::Up)
                    my_player.setPos(sf::Vector2i(my_player.getPos().x, my_player.getPos().y - 1));
                else if (event.key.code == sf::Keyboard::Down)
                    my_player.setPos(sf::Vector2i(my_player.getPos().x, my_player.getPos().y + 1));
            }
        }

        window.clear();

        y = 0;
        while (y < grid_y)
        {
            x = 0;
            while (x < grid_x)
            {
                if (grid[y][x] == '1')
                {
                    rectangle.setFillColor(sf::Color(255, 0, 0));
                }
                else
                {
                    rectangle.setFillColor(sf::Color(0, 255, 0));
                }
                rectangle.setPosition(sf::Vector2f(x * 64, y * 64));
                window.draw(rectangle);
                x += 1;
            }
            y += 1;
        }

        rectangle.setFillColor(sf::Color(0, 0, 255));
        rectangle.setPosition(sf::Vector2f(my_player.getPos().x * 64, my_player.getPos().y * 64));
        window.draw(rectangle);

        window.display();
    }

    return 0;
}