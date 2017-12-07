#include <SFML/Audio.hpp>

#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Valeward");

	Game* game = new Game(&window);

    //sf::Font font;
    //if (!font.loadFromFile("arial.ttf"))
    //    return EXIT_FAILURE;
    //sf::Text text("Hello SFML", font, 50);

    //sf::Music music;
    //if (!music.openFromFile("atmospace_jungle.wav"))
    //    return EXIT_FAILURE;
    //music.play();

    while (game->IsRunning())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
		game->Update();
		game->Render();
    }

	delete game;
}