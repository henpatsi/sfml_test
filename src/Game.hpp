#pragma once

#include <SFML/Graphics.hpp>

#include "Character.hpp"
#include "Enemy.hpp"

#define FPS_FONT_PATH "assets/fonts/Atop-R99O3.ttf"

class Game
{
	Character m_character;

	std::vector<Enemy *> m_enemies;

	// FPS

	sf::Font m_font;
	sf::Text m_FPSText;

	// Input

	InputHandler& m_inputHandler = InputHandler::getInstance();

	void check_collisions();

	public:
		Game(sf::Window& window);

		void update(float delta);
		void render(sf::RenderWindow& window);
};
