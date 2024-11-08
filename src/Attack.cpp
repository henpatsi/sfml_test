#include "Attack.hpp"

Attack::Attack(sf::Vector2f position, sf::Vector2f parentPosition)
{
	m_attackShape.setRadius(ATTACK_RADIUS);
	m_attackShape.setFillColor(sf::Color::Red);

	sf::Vector2f globalPosition = position - sf::Vector2f(ATTACK_RADIUS, ATTACK_RADIUS);
	m_relativePosition = globalPosition - parentPosition;
}

void Attack::update(float delta, sf::Vector2f parentPosition)
{
	m_attackShape.setPosition(parentPosition + m_relativePosition);

	m_lifetime -= delta;

	if (m_lifetime <= 0)
	{
		m_destroy = true;
	}
}

void Attack::render(sf::RenderWindow& window)
{
	window.draw(m_attackShape);
}