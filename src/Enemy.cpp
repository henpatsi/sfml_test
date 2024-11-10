#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f spawnPosition, Character& character) : m_character(character)
{
	if (!m_texture.loadFromFile(ENEMY_SPRITE_SHEET_PATH))
	{
		std::cout << "Failed to load enemy texture" << std::endl;
		exit(1);
	}

	// Initialize sprite
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(ENEMY_SPRITE_SCALE, ENEMY_SPRITE_SCALE);

	m_position = spawnPosition;
}

void Enemy::update(float delta)
{
	// Move towards the player
	sf::Vector2f direction = m_character.getPosition() - m_position;
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (length == 0)
	{
		return;
	}

	direction.x /= length;
	direction.y /= length;
	
	m_position.x += direction.x * m_speed * delta;
	m_position.y += direction.y * m_speed * delta;
}

void Enemy::render(sf::RenderWindow& window)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
	m_sprite.setPosition(m_position);

	window.draw(m_sprite);
}