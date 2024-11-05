#pragma once

#include <SFML/Graphics.hpp>

#define ATTACK_RADIUS 20

class Attack
{
	float m_lifetime = 0.5f;
	bool m_destroy = false;

	sf::CircleShape attackShape;

	public:
		Attack(sf::Vector2f position);

		void update(float delta);
		void render(sf::RenderWindow& window);

		bool shouldDestroy() { return m_destroy; }
};
