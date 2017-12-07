#include "Player.h"



Player::Player(sf::RenderWindow* window, std::string path)
{
	_window = window;
	this->SetSprite(path);
}


Player::~Player()
{
	delete _sprite;
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

void Player::Draw()
{
	_window->draw(*_sprite);
}
