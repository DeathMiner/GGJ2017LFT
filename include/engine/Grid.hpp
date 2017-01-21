#ifndef ENGINE_GRID_H_
# define ENGINE_GRID_H_

class Grid
{
	int sx;
	int sy;
	int scale;
	int *data;
public:
	Grid(const sf::Vector3i& size, int new_data[]);

	sf::Vector2i getSize() const;
	int getScale() const;
	int getTile(float x, float y) const;
	int getTileByPos(int x, int y) const;
	int convertCoord(float x) const;
	float unconvertCoord(int x) const;

};

#endif /* !ENGINE_GRID_H_ */