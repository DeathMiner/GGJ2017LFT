#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine.hpp"

int grid_size = 128;
int grid_x = 20;
int grid_y = 11;
int grid[] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
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

    sf::Texture text_bg;
    text_bg.loadFromFile("Map.jpg");
    sf::Sprite sprite_bg(text_bg);

    sf::Texture text_player_floorleft;
    text_player_floorleft.loadFromFile("Déplacement vers la gauche.png");
    sf::Texture text_player_floorright;
    text_player_floorright.loadFromFile("Déplacement vers la droite.png");
    sf::Sprite sprite_player(text_player_floorright);
    sprite_player.setTextureRect(sf::IntRect(grid_size, 0, grid_size, grid_size));
    float frame = 0;
    sf::Texture text_cube;
    text_cube.loadFromFile("Elément cube 128 par 128.png");
    sf::Sprite sprite_cube(text_cube);

    Level *level = new Level(sf::Vector3i(grid_x, grid_y, grid_size), grid, sf::Vector2f(0, 0));

    int x, y;

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
                else if (event.key.code == sf::Keyboard::Space && !level->player.airbone)
                {
                    level->player.setSpeed(sf::Vector2f(level->player.getSpeed().x, -0.15));
                    level->player.airbone = true;
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    level->player.move_left = true;
                    sprite_player.setTexture(text_player_floorleft);
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    level->player.move_right = true;
                    sprite_player.setTexture(text_player_floorright);
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

        sprite_player.setTextureRect(sf::IntRect(int(frame) * 128, 0, 128, 128));
        frame += (float) 25 / 60;
        if (frame > 25)
            frame = 0;

        window->clear(sf::Color(54, 94, 137));

        window->setView(level->view);

        window->draw(sprite_bg);

        y = 0;
        while (y < level->grid.getSize().y)
        {
            x = 0;
            while (x < level->grid.getSize().x)
            {
                if (level->grid.getTile(x, y) == 1)
                {
                    sprite_cube.setPosition(sf::Vector2f(x * level->grid.getScale(), y * level->grid.getScale()));
                    window->draw(sprite_cube);
                }
                x += 1;
            }
            y += 1;
        }

        /*rectangle.setFillColor(sf::Color(0, 0, 0));
        rectangle.setPosition(sf::Vector2f(level->grid.unconvertCoord(level->grid.convertCoord(level->player.getPos().x)), level->grid.unconvertCoord(level->grid.convertCoord(level->player.getPos().y))));
        window->draw(rectangle);*/
        sprite_player.setPosition(sf::Vector2f(level->player.getPos().x * level->grid.getScale() - level->grid.getScale() / 2, level->player.getPos().y * level->grid.getScale()));
        window->draw(sprite_player);

        camera.x = camera.x * (1 - camera_smooth) + (level->player.getPos().x * level->grid.getScale() - level->grid.getScale() / 2) * camera_smooth;
        camera.y = camera.y * (1 - camera_smooth) + (level->player.getPos().y * level->grid.getScale() - level->grid.getScale() / 2) * camera_smooth;
        level->view.setCenter(camera.x, camera.y);
        level->view.setSize(1920, 1080);

        window->display();
    }

    delete level;
    delete window;

    return 0;
}