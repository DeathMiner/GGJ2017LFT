#include <SFML/Graphics.hpp>
#include "engine.hpp"

Player::Player()
{
	pos = sf::Vector2i(0, 0);
}

void Player::setPos(const sf::Vector2i new_pos)
{
	pos = new_pos;
}

sf::Vector2i Player::getPos() const
{
	return (pos);
}

Player::~Player()
{

}