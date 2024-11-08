#pragma once

#include <SFML/Graphics.hpp>

#define ATTACK_RADIUS 20

class Attack
{
	float m_lifetime = 0.5f;
	bool m_destroy = false;

	sf::Vector2f m_relativePosition;

	sf::CircleShape m_attackShape;

	public:
		Attack(sf::Vector2f position, sf::Vector2f parentPosition);

		void update(float delta, sf::Vector2f parentPosition);
		void render(sf::RenderWindow& window);

		bool shouldDestroy() { return m_destroy; }
};
