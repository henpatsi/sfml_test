#pragma once

#include <SFML/Graphics.hpp>

#include "Character.hpp"
#include "EnemySpawner.hpp"

#define FPS_FONT_PATH "assets/fonts/Atop-R99O3.ttf"

class Game
{
	Character m_character;
	EnemySpawner m_enemySpawner;

	// FPS

	sf::Font m_font;
	sf::Text m_FPSText;

	// Input

	InputHandler& m_inputHandler = InputHandler::getInstance();

	void check_collisions();

	public:
		Game() = delete;
		Game(sf::Window& window);
		~Game();

		void update(float delta);
		void render(sf::RenderWindow& window);
};
