#include "Game.hpp"

Game::Game(sf::Window& window) : m_enemySpawner(1.0f, window.getSize(), m_character), m_UI(window.getSize())
{
}

Game::~Game()
{
}

void Game::start()
{
	m_character.start();
	m_enemySpawner.start();

	m_UI.updatePlayerHealth(m_character.getHealth());
	m_UI.updatePlayerStamina(m_character.getStamina());
	m_UI.updateScore(m_enemySpawner.getScore());

	m_gameState = GameState::GAME;
}

void Game::update(float delta)
{
	if (m_gameState == GameState::MAIN_MENU || m_gameState == GameState::GAME_OVER)
	{
		if (m_inputHandler.wasKeyJustPressed("start_game"))
		{
			start();
		}
	}

	if (m_inputHandler.wasKeyJustPressed("pause"))
	{
		m_gameState = m_gameState == GameState::PAUSED ? GameState::GAME : GameState::PAUSED;
	}

	if (m_gameState == GameState::GAME)
	{
		m_character.update(delta);
		m_enemySpawner.update(delta);

		check_collisions();

		m_UI.updatePlayerStamina(m_character.getStamina());
	}
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
			m_UI.updatePlayerHealth(m_character.getHealth());
			if (m_character.isDead())
			{
				m_gameState = GameState::GAME_OVER;
				m_UI.updateEndScore(m_enemySpawner.getScore());
			}
		}

		for (Attack *attack : attacks)
		{
			sf::Vector2f attackPosition = attack->getPosition();
			float attackCollisionRadius = attack->getCollisionRadius();

			float distance = std::sqrt(std::pow(enemyPosition.x - attackPosition.x, 2) + std::pow(enemyPosition.y - attackPosition.y, 2));

			if (distance < enemyCollisionRadius + attackCollisionRadius)
			{
				enemy->damage(attack->getDamage());
				if (enemy->isDead())
				{
					m_enemySpawner.removeEnemy(enemy);
					m_UI.updateScore(m_enemySpawner.getScore());
				}
			}
		}
	}
}

void Game::render(sf::RenderWindow& window)
{
	if (m_inputHandler.isKeyPressed("close_game"))
	{
		window.close();
	}

	if (m_gameState == GameState::GAME || m_gameState == GameState::PAUSED)
	{
		m_enemySpawner.render(window);
		m_character.render(window);
	}

	m_UI.render(window, m_gameState);
}
