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

	m_pauseText.setFont(m_font);
	m_pauseText.setCharacterSize(128);
	m_pauseText.setString("PAUSED");
	m_pauseText.setPosition(window.getSize().x / 2 - m_pauseText.getGlobalBounds().width / 2,
							window.getSize().y / 2 - m_pauseText.getGlobalBounds().height / 2);
}

Game::~Game()
{
}

void Game::update(float delta)
{
	if (m_inputHandler.wasKeyJustPressed("pause"))
	{
		togglePause();
	}

	if (m_paused)
		return;

	m_character.update(delta);
	
	m_enemySpawner.update(delta);

	check_collisions();

	m_FPSText.setString(std::to_string((int)(1.0f / delta)));
}

void Game::togglePause()
{
	m_paused = !m_paused;
}

void Game::check_collisions()
{
	sf::Vector2f characterPosition = m_character.getPosition();
	float characterCollisionRadius = m_character.getCollisionRadius();

	std::vector<Enemy *>& enemies = m_enemySpawner.getEnemies();
	std::vector<Attack *>& attacks = m_character.getAttacks();

	for (Enemy *enemy : enemies)
	{
		sf::Vector2f enemyPosition = enemy->getPosition();
		float enemyCollisionRadius = enemy->getCollisionRadius();

		float distance = std::sqrt(std::pow(enemyPosition.x - characterPosition.x, 2) + std::pow(enemyPosition.y - characterPosition.y, 2));

		if (distance < enemyCollisionRadius + characterCollisionRadius)
		{
			m_character.damage(enemy->getDamage());
		}

		for (Attack *attack : attacks)
		{
			sf::Vector2f attackPosition = attack->getPosition();
			float attackCollisionRadius = attack->getCollisionRadius();

			float distance = std::sqrt(std::pow(enemyPosition.x - attackPosition.x, 2) + std::pow(enemyPosition.y - attackPosition.y, 2));

			if (distance < enemyCollisionRadius + attackCollisionRadius)
			{
				enemy->damage(attack->getDamage());
			}
		}
	}
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

	if (m_paused)
	{
		window.draw(m_pauseText);
	}
}
