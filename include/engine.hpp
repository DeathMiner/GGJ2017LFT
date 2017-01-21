#ifndef ENGINE_H_
# define ENGINE_H_

#include <SFML/Graphics.hpp>

class Player
{
	sf::Vector2i speed;
	sf::Vector2i pos;
public:
	Player();

	void setPos(const sf::Vector2i new_pos);

	sf::Vector2i getPos() const;

	~Player();

};

#endif /* !ENGINE_H_ */