#pragma once

#include "VisualEntity.h"

class Player : public VisualEntity
{
public:
	Player(sf::RenderWindow* window, std::string path);
	~Player();

	void Draw();
	void SetSprite(std::string path);

private:
	sf::RenderWindow* _window;
	sf::Texture* _texture;
	sf::Sprite* _sprite;
	int _position[2];
};

