#include "Game.h"
#include "Player.h"
#include "Map.h"



Game::Game(sf::RenderWindow* window)
{
	_isRunning = true;
	_window = window;
	_you = new Player(window, "pixelman.png");
	_map = new Map(window);
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
	if (!_window->isOpen())
	{
		_isRunning = false;
		return;
	}

	PollKeyboard();
}
void Game::PollKeyboard()
{
	bool newState[8];

	float xdelta = 0.0f;
	float ydelta = 0.0f;
		
	newState[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::K);
	newState[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::H);
	newState[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::J);
	newState[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::L);
	newState[4] = sf::Keyboard::isKeyPressed(sf::Keyboard::Y);
	newState[5] = sf::Keyboard::isKeyPressed(sf::Keyboard::U);
	newState[6] = sf::Keyboard::isKeyPressed(sf::Keyboard::B);
	newState[7] = sf::Keyboard::isKeyPressed(sf::Keyboard::N);

	if (_keyboardState[0] && !newState[0])	ydelta = -1.0f;
	if (_keyboardState[1] && !newState[1])	xdelta = -1.0f;
	if (_keyboardState[2] && !newState[2])	ydelta = 1.0f;
	if (_keyboardState[3] && !newState[3])	xdelta = 1.0f;
	if (_keyboardState[4] && !newState[4]) { xdelta = -1.0f; ydelta = -1.0f; }
	if (_keyboardState[5] && !newState[5]) { xdelta = 1.0f; ydelta = -1.0f; }
	if (_keyboardState[6] && !newState[6]) { xdelta = -1.0f; ydelta = 1.0f; }
	if (_keyboardState[7] && !newState[7]) { xdelta = 1.0f; ydelta = 1.0f; }

	for (int i = 0; i < 8; i++)
	{
		_keyboardState[i] = newState[i];
	}

	_you->Move(xdelta, ydelta);
}


void Game::Render()
{
	_window->clear();
	_map->Draw();
	_you->Draw();
	_window->display();
}
