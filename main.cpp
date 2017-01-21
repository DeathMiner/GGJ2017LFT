#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine.hpp"

int grid_size = 64;
int grid_x = 20;
int grid_y = 11;
int grid[] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,1,
    0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,
    1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};
float gravity = 1;

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(
        sf::VideoMode(1920, 1080),
        "SFML GGJ2017LFT!",
        sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen
    );
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);

    Level *level = new Level(sf::Vector3i(grid_x, grid_y, grid_size), grid, sf::Vector2f(0, 0));

    int x, y;
    sf::RectangleShape rectangle(sf::Vector2f(level->grid.getScale(), level->grid.getScale()));

    sf::Vector2f camera(0, 0);
    float camera_smooth = 0.1;

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                }
                else if (event.key.code == sf::Keyboard::Space)
                {
                    level->player.setSpeed(sf::Vector2f(level->player.getSpeed().x, -15));
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    level->player.move_left = true;
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    level->player.move_right = true;
                }
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    level->player.move_left = false;
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    level->player.move_right = false;
                }
            }
        }

        level->update();

        window->clear();

        window->setView(level->view);

        y = 0;
        while (y < level->grid.getSize().y * level->grid.getScale())
        {
            x = 0;
            while (x < level->grid.getSize().x * level->grid.getScale())
            {
                if (level->grid.getTile(x, y) == 1)
                {
                    rectangle.setFillColor(sf::Color(255, 0, 0));
                }
                else
                {
                    rectangle.setFillColor(sf::Color(0, 255, 0));
                }
                rectangle.setPosition(sf::Vector2f(x, y));
                window->draw(rectangle);
                x += level->grid.getScale();
            }
            y += level->grid.getScale();
        }

        /*rectangle.setFillColor(sf::Color(0, 0, 0));
        rectangle.setPosition(sf::Vector2f(level->grid.unconvertCoord(level->grid.convertCoord(level->player.getPos().x)), level->grid.unconvertCoord(level->grid.convertCoord(level->player.getPos().y))));
        window->draw(rectangle);*/
        rectangle.setFillColor(sf::Color(0, 0, 255));
        rectangle.setPosition(sf::Vector2f(level->player.getPos().x - level->grid.getScale() / 2, level->player.getPos().y));
        window->draw(rectangle);

        camera.x = camera.x * (1 - camera_smooth) + (level->player.getPos().x - level->grid.getScale() / 2) * camera_smooth;
        camera.y = camera.y * (1 - camera_smooth) + (level->player.getPos().y - level->grid.getScale() / 2) * camera_smooth;
        level->view.setCenter(camera.x, camera.y);
        //level->view.setSize(1280, 720);

        window->display();
    }

    delete level;
    delete window;

    return 0;
}