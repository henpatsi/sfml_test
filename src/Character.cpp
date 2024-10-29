#include "Character.hpp"

Character::Character(void)
{
	if (!m_texture.loadFromFile(SPRITE_SHEET_PATH))
	{
		std::cout << "Failed to load character texture" << std::endl;
		exit(1);
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
}

void Character::update(float delta)
{
	m_position += sf::Vector2f(m_horizontal_input * m_move_speed * delta, m_vertical_input * m_move_speed * delta);

	animateSprite(delta);
}

void Character::animateSprite(float delta)
{
	// Idle
	if (m_horizontal_input == 0 && m_vertical_input == 0)
	{
		setAnimationPositions(m_idle_animation_positions);
	}

	// Horizontal movement
	if (m_horizontal_input != 0)
	{
		if (m_horizontal_input == 1)
		{
			m_sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
			m_sprite.setOrigin(0, 0);
		}
		else if (m_horizontal_input == -1)
		{
			m_sprite.setScale(-SPRITE_SCALE, SPRITE_SCALE);
			m_sprite.setOrigin(SPRITE_SIZE, 0);
		}
		setAnimationPositions(m_walk_side_animation_positions);
	}
	// Vertical movement
	else if (m_vertical_input == -1)
	{
		setAnimationPositions(m_walk_up_animation_positions);
	}
	else if (m_vertical_input == 1)
	{
		setAnimationPositions(m_walk_down_animation_positions);
	}

	m_animation_timer += delta;
	if (m_animation_timer < m_animation_speed)
		return;
	m_animation_timer = 0.0f;

	m_animation_position = m_animation_positions[m_animation_frame];
	m_animation_frame = (m_animation_frame + 1) % m_animation_positions.size();
}

void Character::setAnimationPositions(std::vector<sf::IntRect> &positions)
{
	if (m_animation_positions != positions)
	{
		m_animation_frame = 0;
		m_animation_timer = m_animation_speed;
	}
	m_animation_positions = positions;
}

void Character::render(sf::RenderWindow& window)
{
	m_sprite.setTextureRect(m_animation_position);
	m_sprite.setPosition(m_position);
	window.draw(m_sprite);
}