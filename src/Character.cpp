#include "Character.hpp"

Character::Character()
{
	if (!m_texture.loadFromFile(SPRITE_SHEET_PATH))
	{
		std::cout << "Failed to load character texture" << std::endl;
		exit(1);
	}

	// Initialize sprite
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
	m_sprite.setOrigin(SPRITE_SIZE / 2, SPRITE_SIZE / 2);
}

Character::~Character()
{
	for (Attack* attack : m_attacks)
	{
		delete attack;
	}
}

void Character::start()
{
	m_position = { 100, 100 };

	m_health = 100;
	m_dead = false;
	m_damageTimer = 0.0f;

	m_stamina = 100;
	m_sprinting = false;
	m_horizontalInput = 0;
	m_verticalInput = 0;
	m_direction = Direction::DOWN;

	for (Attack* attack : m_attacks)
	{
		delete attack;
	}
	m_attacks.clear();
}

void Character::update(float delta)
{
	handleInput();

	move(delta);
	attack(delta);

	if (m_damageTimer > 0)
	{
		m_damageTimer -= delta;
	}

	animateSprite(delta);
}

void Character::move(float delta)
{
	float current_speed = m_moveSpeed;

	if (m_sprinting)
	{
		if (m_stamina > 0)
		{
			m_stamina -= m_staminaOnSprint * delta;
			current_speed *= m_sprintModifier;
		}
		else
		{
			m_sprinting = false;
		}
	}
	
	if (!m_sprinting && m_stamina < 100)
	{
		m_stamina += m_staminaRegen * delta;
	}

	m_position += sf::Vector2f(m_horizontalInput * current_speed * delta, m_verticalInput * current_speed * delta);
}

void Character::attack(float delta)
{

	for (auto it = m_attacks.begin(); it != m_attacks.end();)
	{
		if ((*it)->shouldDestroy())
		{
			delete *it;
			it = m_attacks.erase(it);
		}
		else
		{
			(*it)->update(delta, m_position, m_direction);
			it++;
		}
	}

	if (!m_attacking)
		return;

	m_attacks.push_back(new Attack(m_position, m_direction));

	m_attacking = false;
}

void Character::damage(int damage)
{
	if (m_damageTimer > 0)
		return;

	m_health -= damage;
	if (m_health <= 0)
	{
		m_health = 0;
		m_dead = true;
	}

	m_damageTimer = m_damageCooldown;
}

// Input

void Character::handleInput()
{
	m_horizontalInput = 0;
	m_verticalInput = 0;

	if (m_inputHandler.isKeyPressed("move_right"))
	{
		m_horizontalInput += 1;
		m_direction = Direction::RIGHT;
	}
	if (m_inputHandler.isKeyPressed("move_left"))
	{
		m_horizontalInput += -1;
		m_direction = Direction::LEFT;
	}
	if (m_inputHandler.isKeyPressed("move_up"))
	{
		m_verticalInput += -1;
		m_direction = Direction::UP;
	}
	if (m_inputHandler.isKeyPressed("move_down"))
	{
		m_verticalInput += 1;
		m_direction = Direction::DOWN;
	}

	if (m_inputHandler.isKeyPressed("sprint"))
	{
		m_sprinting = true;
	}
	else
	{
		m_sprinting = false;
	}

	if (m_inputHandler.isKeyPressed("attack"))
	{
		if (m_canAttack)
		{
			m_canAttack = false;
			m_attacking = true;
		}
	}
	else
	{
		m_canAttack = true;
	}
}

// Animation

void Character::animateSprite(float delta)
{
	if (m_direction == Direction::LEFT || m_horizontalInput == -1)
	{
		flipSprite(true);
	}
	else
	{
		flipSprite(false);
	}

	// Idle
	if (m_horizontalInput == 0 && m_verticalInput == 0)
	{
		if (m_direction == Direction::DOWN)
		{
			setAnimationPositions(m_idleDownAnimationPositions);
		}
		else if (m_direction == Direction::UP)
		{
			setAnimationPositions(m_idleUpAnimationPositions);
		}
		else
		{
			setAnimationPositions(m_idleSideAnimationPositions);
		}
	}

	// Horizontal movement
	if (m_horizontalInput != 0)
	{
		setAnimationPositions(m_walkSideAnimationPositions);
	}
	// Vertical movement
	else if (m_verticalInput == -1)
	{
		setAnimationPositions(m_walkUpAnimationPositions);
	}
	else if (m_verticalInput == 1)
	{
		setAnimationPositions(m_walkDownAnimationPositions);
	}

	m_animationTimer += delta;
	if (m_animationTimer < m_animationSpeed)
		return;
	m_animationTimer = 0.0f;

	m_animationPosition = m_animationPositions[m_animationFrame];
	m_animationFrame = (m_animationFrame + 1) % m_animationPositions.size();
}

void Character::flipSprite(bool flipped = false)
{
	if (flipped)
	{
		m_sprite.setScale(-SPRITE_SCALE, SPRITE_SCALE);
	}
	else
	{
		m_sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
	}
}

void Character::setAnimationPositions(std::vector<sf::IntRect> &positions)
{
	if (m_animationPositions != positions)
	{
		m_animationFrame = 0;
		m_animationTimer = m_animationSpeed;
	}
	m_animationPositions = positions;
}

// Render

void Character::render(sf::RenderWindow& window)
{
	m_sprite.setTextureRect(m_animationPosition);
	m_sprite.setPosition(m_position);
	
	window.draw(m_sprite);

	for (Attack* attack : m_attacks)
	{
		attack->render(window);
	}
}