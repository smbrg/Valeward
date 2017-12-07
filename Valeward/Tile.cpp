#include "Tile.h"


Tile::Tile(sf::RenderWindow* window, std::string path, float xpos, float ypos)
{
	_window = window;
	_position[0] = _position[1] = 0.0f;
	this->SetPosition(xpos, ypos);
	this->SetSprite(path);
}


Tile::~Tile()
{
	delete _sprite;
	delete _texture;
}


void Tile::SetSprite(std::string path)
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


void Tile::SetPosition(float xpos, float ypos)
{
	_position[0] = xpos;
	_position[1] = ypos;
}

void Tile::Draw()
{
	_sprite->setPosition(_position[0], _position[1]);
	_window->draw(*_sprite);
}
