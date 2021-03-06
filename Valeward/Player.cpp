#include "Player.h"



Player::Player(sf::RenderWindow* window, std::string path)
{
	_window = window;
	this->SetPosition(0.0f, 0.0f);
	this->SetSprite(path);
}


Player::~Player()
{
	delete _sprite;
	delete _texture;
}


void Player::SetSprite(std::string path)
{
	if (_sprite != nullptr)
	{
		delete _sprite;
		_sprite = nullptr;
	}
	if (_texture != nullptr)
	{
		delete _texture;
		_texture = nullptr;
	}

	_texture = new sf::Texture();
	_texture->loadFromFile(path);
	_sprite = new sf::Sprite(*_texture);
}

void Player::SetPosition(float xpos, float ypos)
{
	_position[0] = xpos;
	_position[1] = ypos;
}

void Player::Move(float xdelta, float ydelta)
{
	_position[0] += xdelta;
	_position[1] += ydelta;
}

void Player::Draw()
{
	_sprite->setPosition(_position[0]*32, _position[1]*32);
	_window->draw(*_sprite);
}
