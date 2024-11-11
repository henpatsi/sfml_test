#pragma once

#include <SFML/Graphics.hpp>

#include "InputHandler.hpp"
#include "Character.hpp"
#include "EnemySpawner.hpp"
#include "UI.hpp"

class Game
{
	Character m_character;
	EnemySpawner m_enemySpawner;

	UI m_UI;

	GameState m_gameState = GameState::MAIN_MENU;

	// Input

	InputHandler& m_inputHandler = InputHandler::getInstance();

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
