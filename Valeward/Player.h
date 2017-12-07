#pragma once

#include "VisualEntity.h"

class Player : public VisualEntity
{
public:
	Player(sf::RenderWindow* window, std::string path);
	~Player();

	void Draw();
	void SetSprite(std::string path);
	void SetPosition(float xpos, float ypos);
	void Move(float xdelta, float ydelta);

private:
	sf::RenderWindow* _window;
	sf::Texture* _texture;
	sf::Sprite* _sprite;
	float _position[2];
};

