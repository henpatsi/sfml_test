#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "InputHandler.hpp"
#include "Attack.hpp"
#include "Enums.hpp"

#define SPRITE_SHEET_PATH "assets/character/character_spritesheet.png"
#define SPRITE_SCALE 4
#define SPRITE_SIZE 32

#define STAMINA_FONT_PATH "assets/fonts/Atop-R99O3.ttf"

class Character
{
	InputHandler& m_inputHandler = InputHandler::getInstance();

	int m_health = 100;
	bool m_dead = false;
	float m_damageTimer = 0.0f;
	float m_damageCooldown = 1.0f;
	float m_collisionRadius = SPRITE_SIZE / 4 * SPRITE_SCALE;

	// Movement
	int m_moveSpeed = 100;

	float m_stamina = 100;
	float m_staminaRegen = 10;

	bool m_sprinting = false;
	float m_sprintModifier = 2;
	float m_staminaOnSprint = 50;

	int m_horizontalInput = 0;
	int m_verticalInput = 0;
	int m_direction = Direction::DOWN;

	sf::Vector2f m_position = {0, 0};

	void move(float delta);

	// Attack

	bool m_canAttack = true;
	bool m_attacking = false;

	std::vector<Attack*> m_attacks;

	void attack(float delta);

	// Text

	sf::Font m_font;
	sf::Text m_staminaText;
	sf::Text m_healthText;

	// Sprite

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	// Animation

	int m_animationFrame = 0;
	std::vector<sf::IntRect> m_animationPositions;
	sf::IntRect m_animationPosition = {0, 0, SPRITE_SIZE, SPRITE_SIZE};
	float m_animationTimer = 0.0f;
	float m_animationSpeed = 0.2f;

	std::vector<sf::IntRect> m_idleDownAnimationPositions = {
		sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_idleSideAnimationPositions = {
		sf::IntRect(0, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_idleUpAnimationPositions = {
		sf::IntRect(0, SPRITE_SIZE * 2, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 2, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walkSideAnimationPositions = {
		sf::IntRect(0, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 4, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walkDownAnimationPositions = {
		sf::IntRect(0, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
		sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE),
	};

	std::vector<sf::IntRect> m_walkUpAnimationPositions = {
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
		~Character();

		void setSprinting(bool sprinting) { m_sprinting = sprinting; }

		sf::Vector2f getPosition() { return m_position; }
		float getCollisionRadius() { return m_collisionRadius; }

		std::vector<Attack*>& getAttacks() { return m_attacks; }
		void damage(int damage);
		int getHealth() { return m_health; }
		bool isDead() { return m_dead; }

		void update(float delta);
		void handleInput();
		void render(sf::RenderWindow& window);
};
