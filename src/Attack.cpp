#include "Attack.hpp"

Attack::Attack(sf::Vector2f parentPosition, int parentDirection)
{
	updatePosition(parentPosition, parentDirection);
	m_attackShape.setRadius(ATTACK_RADIUS);
	m_attackShape.setFillColor(sf::Color::Red);
}

void Attack::update(float delta, sf::Vector2f parentPosition, int parentDirection)
{
	updatePosition(parentPosition, parentDirection);

	m_lifetime -= delta;

	if (m_lifetime <= 0)
	{
		m_destroy = true;
	}
}

void Attack::updatePosition(sf::Vector2f parentPosition, int parentDirection)
{
	sf::Vector2f globalPosition = parentPosition;
	globalPosition -= sf::Vector2f(ATTACK_RADIUS, ATTACK_RADIUS);

	if (parentDirection == Direction::LEFT)
	{
		globalPosition.x -= m_attackShapeOffset;
	}
	else if (parentDirection == Direction::RIGHT)
	{
		globalPosition.x += m_attackShapeOffset;
	}
	else if (parentDirection == Direction::UP)
	{
		globalPosition.y -= m_attackShapeOffset;
	}
	else if (parentDirection == Direction::DOWN)
	{
		globalPosition.y += m_attackShapeOffset;
	}

	m_attackShape.setPosition(globalPosition);
}

void Attack::render(sf::RenderWindow& window)
{
	window.draw(m_attackShape);
}