#include "Character.hpp"

Character::Character()
{
	if (!m_texture.loadFromFile(SPRITE_SHEET_PATH))
	{
		std::cout << "Failed to load character texture" << std::endl;
		exit(1);
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);

	if (!m_font.loadFromFile(STAMINA_FONT_PATH))
	{
		std::cout << "Failed to load stamina font" << std::endl;
		exit(1);
	}

	m_staminaText.setFont(m_font);
	m_staminaText.setCharacterSize(24);
	m_staminaText.setFillColor(sf::Color::Green);
	m_staminaText.setPosition(200, 0);
}

void Character::update(float delta)
{
	handleInput();

	float current_speed = m_move_speed;

	if (m_sprinting)
	{
		if (m_stamina > 0)
		{
			m_stamina -= m_stamina_on_sprint * delta;
			current_speed *= m_sprint_modifier;
		}
		else
		{
			m_sprinting = false;
		}
	}
	
	if (!m_sprinting && m_stamina < 100)
	{
		m_stamina += m_stamina_regen * delta;
	}

	m_staminaText.setString("Stamina: " + std::to_string((int)m_stamina));

	m_position += sf::Vector2f(m_horizontal_input * current_speed * delta, m_vertical_input * current_speed * delta);

	animateSprite(delta);
}

void Character::handleInput()
{
	m_horizontal_input = 0;
	m_vertical_input = 0;

	if (g_input.isKeyPressed("move_right"))
	{
		m_horizontal_input += 1;
	}
	if (g_input.isKeyPressed("move_left"))
	{
		m_horizontal_input += -1;
	}
	if (g_input.isKeyPressed("move_up"))
	{
		m_vertical_input += -1;
	}
	if (g_input.isKeyPressed("move_down"))
	{
		m_vertical_input += 1;
	}

	if (g_input.isKeyPressed("sprint"))
	{
		m_sprinting = true;
	}
	else
	{
		m_sprinting = false;
	}
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
	window.draw(m_staminaText);
}