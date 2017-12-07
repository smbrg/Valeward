#pragma once

#include "Player.h"

class Game
{
public:
	Game(sf::RenderWindow* window);
	~Game();

	bool IsRunning();
	void Update();
	void Render();

private:
	sf::RenderWindow* _window;
	Player* _you;
	bool _isRunning;
};

