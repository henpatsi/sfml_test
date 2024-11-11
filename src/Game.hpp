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
	sf::Text m_pauseText;

	sf::Text m_startText;
	sf::Text m_controlsText;

	sf::Text m_gameOverText;
	sf::Text m_scoreText;

	// Input

	InputHandler& m_inputHandler = InputHandler::getInstance();

	bool m_paused = false;
	bool m_gameStarted = false;

	void check_collisions();

	public:
		Game() = delete;
		Game(sf::Window& window);
		~Game();

		void togglePause();

		void start();
		void update(float delta);
		void render(sf::RenderWindow& window);
};
