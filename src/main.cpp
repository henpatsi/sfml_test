#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>

#include "Game.hpp"

int main()
{
	auto window = sf::RenderWindow({1280u, 720u}, "SFML Test");
	window.setFramerateLimit(144);

	sf::Clock clock;
	Game game(window);
	InputHandler& m_inputHandler = InputHandler::getInstance();

	sf::Music music;
	if (!music.openFromFile("./assets/music/Clement_Panchout_Best_Party_Ever_2019.wav"))
		return -1;
	music.play();

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
					m_inputHandler.keyPressed(event.key);
					break;
				
				// key released
				case sf::Event::KeyReleased:
					m_inputHandler.keyReleased(event.key);
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
