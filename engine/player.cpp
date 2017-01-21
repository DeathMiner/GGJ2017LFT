#include <SFML/Graphics.hpp>
#include "engine.hpp"

/*Player::Player()
{
	pos = sf::Vector2f(0, 0);
}

void Player::setPos(const sf::Vector2f new_pos)
{
	pos = new_pos;
}
sf::Vector2f Player::getPos() const
{
	return (pos);
}
void Player::setPosX(const float new_pos)
{
	pos.x = new_pos;
}
float Player::getPosX() const
{
	return (pos.x);
}
void Player::setPosY(const float new_pos)
{
	pos.y = new_pos;
}
float Player::getPosY() const
{
	return (pos.y);
}

void Player::setSpeed(const sf::Vector2f new_speed)
{
	speed = new_speed;
}
sf::Vector2f Player::getSpeed() const
{
	return (speed);
}
void Player::setSpeedX(const float new_speed)
{
	speed.x = new_speed;
}
float Player::getSpeedX() const
{
	return (speed.x);
}
void Player::setSpeedY(const float new_speed)
{
	speed.y = new_speed;
}
float Player::getSpeedY() const
{
	return (speed.y);
}

Player::~Player()
{

}*/

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

	px += sx;
	py += sy;
}