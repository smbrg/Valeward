#include "Map.h"


Map::Map(sf::RenderWindow* window)
{
	_window = window;

	for (int i= 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			_tiles.push_back(new Tile(window, "grass.png", static_cast<float>(i*TILE_SIZE), static_cast<float>(j*TILE_SIZE)));
		}
	}
}

Map::~Map()
{
	for each (Tile* tile in _tiles)
	{
		delete tile;
	}
}

void Map::Draw()
{
	for each (Tile* tile in _tiles)
	{
		tile->Draw();
	}
}
