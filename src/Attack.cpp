#include "Attack.hpp"

Attack::Attack(sf::Vector2f position)
{
	attackShape.setPosition(position - sf::Vector2f(ATTACK_RADIUS, ATTACK_RADIUS));
	attackShape.setRadius(ATTACK_RADIUS);
	attackShape.setFillColor(sf::Color::Red);
}

void Attack::update(float delta)
{
	m_lifetime -= delta;

	if (m_lifetime <= 0)
	{
		m_destroy = true;
	}
}

void Attack::render(sf::RenderWindow& window)
{
	window.draw(attackShape);
}