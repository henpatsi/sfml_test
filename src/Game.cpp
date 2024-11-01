#include "Game.hpp"

Game::Game()
{
	if (!m_font.loadFromFile(FPS_FONT_PATH))
	{
		std::cout << "Failed to load FPS font" << std::endl;
		exit(1);
	}

	m_FPSText.setFont(m_font);
	m_FPSText.setCharacterSize(24);
}

void Game::update(float delta)
{
	m_character.update(delta);

	m_FPSText.setString(std::to_string((int)(1.0f / delta)));
}

void Game::render(sf::RenderWindow& window)
{
	m_character.render(window);

	window.draw(m_FPSText);
}
