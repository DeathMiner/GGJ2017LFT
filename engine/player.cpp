#include <SFML/Graphics.hpp>
#include "engine.hpp"

Player::Player(const sf::Vector2f& spawn):
	px(spawn.x), py(spawn.y)
{

}

sf::Vector2f Player::getPos() const
{
	return (sf::Vector2f(px, py));
}

sf::Vector2f Player::getSpeed() const
{
	return (sf::Vector2f(sx, sy));
}

void Player::setPos(const sf::Vector2f& new_coords)
{
	px = new_coords.x;
	py = new_coords.y;
}

void Player::setSpeed(const sf::Vector2f& new_speed)
{
	sx = new_speed.x;
	sy = new_speed.y;
}

void Player::update()
{
	// Gravity
	sy += 0.5;

	// Horizontal smoothing
	if (sx < 0)
		sx += 1;
	else if (sx > 0)
		sx -= 1;

	// Movements
	if (move_left && move_right)
	{
		sx = 0;
	}
	else if (move_left)
	{
		sx = -10;
	}
	else if (move_right)
	{
		sx = 10;
	}

	// Update position according to speed
	px += sx;
	py += sy;
}