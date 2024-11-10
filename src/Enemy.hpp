#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Character.hpp"

#define ENEMY_SPRITE_SHEET_PATH "assets/character/character_spritesheet.png"
#define ENEMY_SPRITE_SCALE 2
#define SPRITE_SIZE 32

class Enemy
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_position;

	Character& m_character;

	float m_speed = 100.0f;

	public:
		Enemy() = delete;
		Enemy(sf::Vector2f spawnPosition, Character& character);

		void update(float delta);
		void render(sf::RenderWindow& window);
};