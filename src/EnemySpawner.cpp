#include "EnemySpawner.hpp"

EnemySpawner::EnemySpawner(float spawnRate, sf::Vector2u windowSize, Character& character) : m_character(character)
{
	m_spawnRate = spawnRate;
	m_windowSize = windowSize;
}

EnemySpawner::~EnemySpawner()
{
	for (Enemy* enemy : m_enemies)
	{
		delete enemy;
	}
}

void EnemySpawner::spawnEnemy(sf::Vector2f position)
{
	m_enemies.push_back(new Enemy(position));
}

void EnemySpawner::update(float delta)
{
	sf::Vector2f targetPosition = m_character.getPosition();

	for (auto it = m_enemies.begin(); it != m_enemies.end();)
	{
		if ((*it)->shouldDestroy())
		{
			delete *it;
			it = m_enemies.erase(it);
		}
		else
		{
			(*it)->update(delta, targetPosition);
			it++;
		}
	}

	m_spawnTimer += delta;
	if (m_spawnTimer >= m_spawnRate)
	{
		m_spawnTimer = 0.0f;
		
		int dir = rand() % 4;
		if (dir == Direction::UP)
		{
			spawnEnemy(sf::Vector2f(rand() % m_windowSize.x, 0));
		}
		else if (dir == Direction::DOWN)
		{
			spawnEnemy(sf::Vector2f(rand() % m_windowSize.x, m_windowSize.y));
		}
		else if (dir == Direction::LEFT)
		{
			spawnEnemy(sf::Vector2f(0, rand() % m_windowSize.y));
		}
		else if (dir == Direction::RIGHT)
		{
			spawnEnemy(sf::Vector2f(m_windowSize.x, rand() % m_windowSize.y));
		}
	}
}

void EnemySpawner::render(sf::RenderWindow& window)
{
	for (Enemy* enemy : m_enemies)
	{
		enemy->render(window);
	}
}