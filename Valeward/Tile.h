#pragma once

#include "VisualEntity.h"

#define TILE_SIZE		32

class Tile : public VisualEntity
{
public:
	Tile(sf::RenderWindow* window, std::string path, float xpos, float ypos);
	~Tile();

	void Draw();
	void SetSprite(std::string path);
	void SetPosition(float xpos, float ypos);

private:
	sf::RenderWindow* _window;
	sf::Texture* _texture;
	sf::Sprite* _sprite;
	float _position[2];
};

