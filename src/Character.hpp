#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "InputHandler.hpp"

#define SPRITE_SHEET_PATH "assets/character/character_spritesheet.png"
#define SPRITE_SCALE 4
#define SPRITE_SIZE 32

#define STAMINA_FONT_PATH "assets/fonts/Atop-R99O3.ttf"

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

class Character
{
	InputHandler& m_inputHandler = InputHandler::getInstance();

	// Movement
	int m_move_speed = 100;

	float m_stamina = 100;
	float m_stamina_regen = 10;

	bool m_sprinting = false;
	float m_sprint_modifier = 2;
	float m_stamina_on_sprint = 50;

	int m_horizontal_input = 0;
	int m_vertical_input = 0;
	int m_direction = Direction::DOWN;

	sf::Vector2f m_position = {0, 0};

	// Text

	sf::Font m_font;
	sf::Text m_staminaText;

	// Sprite

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	// Animation

	int m_animation_frame = 0;
	std::vector<sf::IntRect> m_animation_positions;
	sf::IntRect m_animation_position = {0, 0, SPRITE_SIZE, SPRITE_SIZE};
	float m_animation_timer = 0.0f;
	float m_animation_speed = 0.2f;

	std::vector<sf::IntRect> m_idle_down_animation_positions = {
		sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_idle_side_animation_positions = {
		sf::IntRect(0, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_idle_up_animation_positions = {
		sf::IntRect(0, SPRITE_SIZE * 2, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 2, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walk_side_animation_positions = {
		sf::IntRect(0, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walk_down_animation_positions = {
		sf::IntRect(0, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walk_up_animation_positions = {
		sf::IntRect(0, SPRITE_SIZE * 5, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 5, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 5, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 5, SPRITE_SIZE, SPRITE_SIZE),
	};

	void animateSprite(float delta);
	void flipSprite(bool flipped);
	void setAnimationPositions(std::vector<sf::IntRect> &positions);

	public:
		Character(void);

		void setSprinting(bool sprinting) { m_sprinting = sprinting; }

		void update(float delta);
		void handleInput();
		void render(sf::RenderWindow& window);
};
