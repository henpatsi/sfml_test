#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define ENEMY_SPRITE_SHEET_PATH "assets/character/character_spritesheet.png"
#define ENEMY_SPRITE_SCALE 2
#define ENEMY_SPRITE_SIZE 32

class Enemy
{
	float m_collisionRadius = ENEMY_SPRITE_SIZE / 2 * ENEMY_SPRITE_SCALE;
	int m_damage = 1;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_position;

	float m_speed = 100.0f;

	int m_health = 100;
	bool m_dead = false;

	public:
		Enemy() = delete;
		Enemy(sf::Vector2f spawnPosition);

		sf::Vector2f getPosition() { return m_position; }
		float getCollisionRadius() { return m_collisionRadius; }
		int getDamage() { return m_damage; }

		void update(float delta, sf::Vector2f targetPosition);
		void render(sf::RenderWindow& window);

		void damage(int damage);
		bool shouldDestroy() { return m_dead; }
};