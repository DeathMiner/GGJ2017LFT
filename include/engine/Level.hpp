#ifndef ENGINE_LEVEL_H_
# define ENGINE_LEVEL_H_

# include <SFML/Graphics.hpp>
# include <engine/Grid.hpp>
# include <engine/Player.hpp>

class Level
{
	//Entity entities[];
public:
	Player player;
	sf::View view;
	Grid grid;

	Level(const sf::Vector3i& size, int new_data[], const sf::Vector2f& spawn);

	void update();
};

#endif /* !ENGINE_LEVEL_H_ */