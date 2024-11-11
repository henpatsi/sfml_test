#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Enums.hpp"

#define UI_FONT_PATH "assets/fonts/m3x6.ttf"
#define FONT_SCALE 2

class UI
{
	sf::Font m_font;

	sf::Text m_scoreText;
	sf::Text m_healthText;
	sf::Text m_staminaText;

	sf::Text m_pauseText;

	sf::Text m_startText;
	sf::Text m_controlsText;

	sf::Text m_gameOverText;
	sf::Text m_endScoreText;

	public:
		UI() = delete;
		UI(sf::Vector2u windowSize);

		void updatePlayerHealth(int health) { m_healthText.setString("Health: " + std::to_string(health)); }
		void updatePlayerStamina(int stamina) { m_staminaText.setString("Stamina: " + std::to_string(stamina)); }
		void updateScore(int score) { m_scoreText.setString("Score: " + std::to_string(score)); }
		void updateEndScore(int score) { m_endScoreText.setString("Score: " + std::to_string(score)); }
		void render(sf::RenderWindow& window, GameState gameState);
};