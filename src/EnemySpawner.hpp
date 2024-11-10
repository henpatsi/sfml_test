#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Enums.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

class EnemySpawner
{
	float m_spawnTimer;
	float m_spawnRate;
	sf::Vector2u m_windowSize;

	std::vector<Enemy *> m_enemies;
	Character& m_character;

	public:
		EnemySpawner() = delete;
		EnemySpawner(float spawnRate, sf::Vector2u windowSize, Character& character);
		~EnemySpawner();

		void spawnEnemy(sf::Vector2f position);

		void update(float delta);
		void render(sf::RenderWindow& window);
};