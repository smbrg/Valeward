#include "Game.h"
#include "Player.h"
#include "Map.h"



Game::Game(sf::RenderWindow* window)
{
	_isRunning = true;
	_window = window;
	_you = new Player(window, "player.png");
}


Game::~Game()
{
	delete _you;
}

bool Game::IsRunning()
{
	return _isRunning;
}

void Game::Update()
{
	//_you->Update();
	if (!_window->isOpen())
		_isRunning = false;
}

void Game::Render()
{
	_window->clear();
	_you->Draw();
	_window->display();
}
