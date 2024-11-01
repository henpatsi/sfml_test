#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "Globals.hpp"

int main()
{
    auto window = sf::RenderWindow({1280u, 720u}, "SFML Test");
    window.setFramerateLimit(144);

	sf::Clock clock;
	Game game;

    while (window.isOpen())
    {
		sf::Time time_passed = clock.restart();

        for (auto event = sf::Event(); window.pollEvent(event);)
        {
			switch (event.type)
			{
				// window closed
				case sf::Event::Closed:
					window.close();
					break;

				// key pressed
				case sf::Event::KeyPressed:
					g_input.keyPressed(event.key);
					break;
				
				// key released
				case sf::Event::KeyReleased:
					g_input.keyReleased(event.key);
					break;

				// we don't process other types of events
				default:
					break;
			}
        }

		game.update(time_passed.asSeconds());

        window.clear();

		game.render(window);

        window.display();
    }
}
