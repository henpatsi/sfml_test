#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define SPRITE_SHEET_PATH "assets/character/character_spritesheet.png"
#define SPRITE_SCALE 4
#define SPRITE_SIZE 32

class Character
{
	// Movement

	int m_move_speed = 100;

	int m_horizontal_input = 0;
	int m_vertical_input = 0;

	sf::Vector2f m_position = {0, 0};

	// Sprite

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	// Animation

	int m_animation_frame = 0;
	std::vector<sf::IntRect> m_animation_positions;
	sf::IntRect m_animation_position = {0, 0, SPRITE_SIZE, SPRITE_SIZE};
	float m_animation_timer = 0.0f;
	float m_animation_speed = 0.2f;

	std::vector<sf::IntRect> m_idle_animation_positions = {
		sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walk_side_animation_positions = {
		sf::IntRect(0, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walk_up_animation_positions = {
		sf::IntRect(0, SPRITE_SIZE * 5, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 5, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 5, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 5, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walk_down_animation_positions = {
		sf::IntRect(0, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
	};

	void animateSprite(float delta);
	void setAnimationPositions(std::vector<sf::IntRect> &positions);

	public:
		Character(void);

		void addHorizontalInput(int x) { m_horizontal_input += x; }
		void addVerticalInput(int y) { m_vertical_input += y; }

		void update(float delta);
		void render(sf::RenderWindow& window);
};
