#pragma once

#include <SFML/Graphics.hpp>

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
