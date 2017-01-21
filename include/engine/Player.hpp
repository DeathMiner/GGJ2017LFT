#ifndef ENGINE_PLAYER_H_
# define ENGINE_PLAYER_H_

# include <SFML/Graphics.hpp>

class Player
{
	float px;
	float py;
	float sx = 0;
	float sy = 0;
public:
	Player(const sf::Vector2f& spawn);

	void setPos(const sf::Vector2f& new_coords);
	void setSpeed(const sf::Vector2f& new_coords);
	sf::Vector2f getPos() const;
	sf::Vector2f getSpeed() const;

	void update();
};

#endif /* !ENGINE_PLAYER_H_ */