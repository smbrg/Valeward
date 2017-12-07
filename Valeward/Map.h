#pragma once

#include "Tile.h"

class Map
{
public:
	Map(sf::RenderWindow* window);
	~Map();

	void Draw();

private:
	sf::RenderWindow* _window;
	std::vector<Tile*> _tiles;
};

