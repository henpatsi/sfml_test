#include "UI.hpp"

UI::UI(sf::Vector2u windowSize)
{
	if (!m_font.loadFromFile(UI_FONT_PATH))
	{
		std::cout << "Failed to load FPS font" << std::endl;
		exit(1);
	}

	m_scoreText.setFont(m_font);
	m_scoreText.setCharacterSize(24 * FONT_SCALE);
	m_scoreText.setFillColor(sf::Color::White);
	m_scoreText.setPosition(20, 0);

	m_staminaText.setFont(m_font);
	m_staminaText.setCharacterSize(24 * FONT_SCALE);
	m_staminaText.setFillColor(sf::Color::Green);
	m_staminaText.setPosition(220, 0);

	m_healthText.setFont(m_font);
	m_healthText.setCharacterSize(24 * FONT_SCALE);
	m_healthText.setFillColor(sf::Color::Red);
	m_healthText.setPosition(420, 0);

	m_pauseText.setFont(m_font);
	m_pauseText.setCharacterSize(64 * FONT_SCALE);
	m_pauseText.setString("PAUSED");
	m_pauseText.setPosition(windowSize.x / 2 - m_pauseText.getGlobalBounds().width / 2,
							windowSize.y / 2 - m_pauseText.getGlobalBounds().height / 2);

	m_startText.setFont(m_font);
	m_startText.setCharacterSize(64 * FONT_SCALE);
	m_startText.setString("PRESS ENTER TO START");
	m_startText.setPosition(windowSize.x / 2 - m_startText.getGlobalBounds().width / 2,
							windowSize.y / 2 - m_startText.getGlobalBounds().height / 2);

	m_controlsText.setFont(m_font);
	m_controlsText.setCharacterSize(24 * FONT_SCALE);
	m_controlsText.setString("WASD - move\nK - attack\nSpace - pause");
	m_controlsText.setPosition(windowSize.x / 2 - m_controlsText.getGlobalBounds().width / 2,
							windowSize.y / 2 - m_controlsText.getGlobalBounds().height / 2 + 200);

	m_gameOverText.setFont(m_font);
	m_gameOverText.setCharacterSize(64 * FONT_SCALE);
	m_gameOverText.setString("GAME OVER");
	m_gameOverText.setPosition(windowSize.x / 2 - m_gameOverText.getGlobalBounds().width / 2,
							windowSize.y / 2 - m_gameOverText.getGlobalBounds().height / 2);
	
	m_endScoreText.setFont(m_font);
	m_endScoreText.setCharacterSize(32 * FONT_SCALE);
}



void UI::render(sf::RenderWindow& window, GameState gameState)
{
	switch (gameState)
	{
		case MAIN_MENU:
			window.draw(m_startText);
			window.draw(m_controlsText);
			break;
		case GAME:
			window.draw(m_scoreText);
			window.draw(m_healthText);
			window.draw(m_staminaText);
			break;
		case PAUSED:
			window.draw(m_pauseText);
			window.draw(m_scoreText);
			break;
		case GAME_OVER:
			window.draw(m_gameOverText);
			m_endScoreText.setPosition(window.getSize().x / 2 - m_endScoreText.getGlobalBounds().width / 2,
							window.getSize().y / 2 - m_endScoreText.getGlobalBounds().height / 2 + 200);
			window.draw(m_endScoreText);
			break;
	}
}