#include "Game.hpp"

Game::Game(sf::Window& window)
{
	if (!m_font.loadFromFile(FPS_FONT_PATH))
	{
		std::cout << "Failed to load FPS font" << std::endl;
		exit(1);
	}

	m_FPSText.setFont(m_font);
	m_FPSText.setCharacterSize(24);

	m_enemies.push_back(new Enemy(sf::Vector2f(0,0), m_character));
	m_enemies.push_back(new Enemy(sf::Vector2f(window.getSize().x, 0), m_character));
	m_enemies.push_back(new Enemy(sf::Vector2f(0, window.getSize().y), m_character));
	m_enemies.push_back(new Enemy(sf::Vector2f(window.getSize().x, window.getSize().y), m_character));
}

void Game::update(float delta)
{
	m_character.update(delta);
	
	for (Enemy* enemy : m_enemies)
	{
		enemy->update(delta);
	}

	check_collisions();

	m_FPSText.setString(std::to_string((int)(1.0f / delta)));
}

void Game::check_collisions()
{
	return;
}

void Game::render(sf::RenderWindow& window)
{
	for (Enemy* enemy : m_enemies)
	{
		enemy->render(window);
	}

	m_character.render(window);

	window.draw(m_FPSText);

	if (m_inputHandler.isKeyPressed("close_game"))
	{
		window.close();
	}
}
