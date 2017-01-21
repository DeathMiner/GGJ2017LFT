#include <SFML/Graphics.hpp>
#include "engine.hpp"

Grid::Grid(const sf::Vector3i& size, int new_data[]):
	sx(size.x), sy(size.y), scale(size.z), data(new_data)
{

}

sf::Vector2i Grid::getSize() const
{
	return (sf::Vector2i(sx, sy));
}
int Grid::getScale() const
{
	return (scale);
}
int Grid::getTileByPos(int x, int y) const
{
	if (x < 0 || x >= sx || y < 0 || y >= sy)
	{
		return (-1);
	}
	return (data[y * sx + x]);
}
int Grid::convertCoord(float x) const
{
	return ((int) x / scale);
}
float Grid::unconvertCoord(int x) const
{
	return (x * scale);
}
int Grid::getTile(float x, float y) const
{
	return (getTileByPos(convertCoord(x), convertCoord(y)));
}