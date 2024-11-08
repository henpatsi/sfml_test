#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Enums.hpp"

#define ATTACK_RADIUS 20

class Attack
{
	float m_lifetime = 0.5f;
	bool m_destroy = false;

	sf::Vector2f m_relativePosition;

	sf::CircleShape m_attackShape;
	int m_attackShapeOffset = 40;

	public:
		Attack(sf::Vector2f parentPosition, int parentDirections);

		void update(float delta, sf::Vector2f parentPosition, int parentDirection);
		void render(sf::RenderWindow& window);

		void updatePosition(sf::Vector2f parentPosition, int parentDirection);
		bool shouldDestroy() { return m_destroy; }
};
