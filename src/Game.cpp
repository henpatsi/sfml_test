#include "Game.hpp"

Game::Game(sf::Window& window) : m_enemySpawner(1.0f, window.getSize(), m_character)
{
	if (!m_font.loadFromFile(FPS_FONT_PATH))
	{
		std::cout << "Failed to load FPS font" << std::endl;
		exit(1);
	}

	m_FPSText.setFont(m_font);
	m_FPSText.setCharacterSize(24);
}

Game::~Game()
{
}

void Game::update(float delta)
{
	m_character.update(delta);
	
	m_enemySpawner.update(delta);

	check_collisions();

	m_FPSText.setString(std::to_string((int)(1.0f / delta)));
}

void Game::check_collisions()
{
	return;
}

void Game::render(sf::RenderWindow& window)
{
	m_enemySpawner.render(window);

	m_character.render(window);

	window.draw(m_FPSText);

	if (m_inputHandler.isKeyPressed("close_game"))
	{
		window.close();
	}
}
