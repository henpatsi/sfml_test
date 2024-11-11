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

void EnemySpawner::removeEnemy(Enemy* enemy)
{
	auto it = std::find(m_enemies.begin(), m_enemies.end(), enemy);
	if (it != m_enemies.end())
	{
		delete *it;
		m_enemies.erase(it);
		m_score += 1;
	}
}

void EnemySpawner::start()
{
	m_score = 0;
	m_spawnTimer = 0.0f;

	for (Enemy* enemy : m_enemies)
	{
		delete enemy;
	}
	m_enemies.clear();
}

void EnemySpawner::update(float delta)
{
	sf::Vector2f targetPosition = m_character.getPosition();

	for (Enemy* enemy : m_enemies)
	{
		enemy->update(delta, targetPosition);
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