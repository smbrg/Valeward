#pragma once

#include "Player.h"
#include "Map.h"

class Game
{
public:
	Game(sf::RenderWindow* window);
	~Game();

	bool IsRunning();
	void Update();
	void Render();
	void PollKeyboard();

private:
	sf::RenderWindow* _window;
	Player* _you;
	Map* _map;
	bool _keyboardState[8];
	bool _isRunning;
};

