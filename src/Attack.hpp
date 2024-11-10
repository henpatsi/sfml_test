#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Enums.hpp"

#define ATTACK_RADIUS 20

class Attack
{
	float m_collisionRadius = ATTACK_RADIUS;

	float m_lifetime = 0.5f;
	bool m_destroy = false;

	sf::CircleShape m_attackShape;
	int m_attackShapeOffset = 40;

	int m_damage = 100;

	public:
		Attack(sf::Vector2f parentPosition, int parentDirections);

		sf::Vector2f getPosition() { return m_attackShape.getPosition(); }
		float getCollisionRadius() { return m_collisionRadius; }
		int getDamage() { return m_damage; }

		void update(float delta, sf::Vector2f parentPosition, int parentDirection);
		void render(sf::RenderWindow& window);

		void updatePosition(sf::Vector2f parentPosition, int parentDirection);
		bool shouldDestroy() { return m_destroy; }
};
