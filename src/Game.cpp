#include "Game.hpp"

Game::Game()
{
	if (!m_font.loadFromFile(FPS_FONT_PATH))
	{
		std::cout << "Failed to load FPS font" << std::endl;
		exit(1);
	}

	m_FPSText.setFont(m_font);
	m_FPSText.setCharacterSize(24);
}

void Game::update(float delta)
{
	m_character.update(delta);

	m_FPSText.setString(std::to_string((int)(1.0f / delta)));
}

void Game::render(sf::RenderWindow& window)
{
	m_character.render(window);

	window.draw(m_FPSText);
}

void Game::input(int code, bool pressed)
{
	if (code == m_moveRight.getCode())
	{
		if (pressed && !m_moveRight.isPressed()) // Was just pressed
			m_character.addHorizontalInput(1);
		else if (!pressed && m_moveRight.isPressed()) // Was just released
			m_character.addHorizontalInput(-1);
	}
	else if (code == m_moveLeft.getCode())
	{
		if (pressed && !m_moveLeft.isPressed())
			m_character.addHorizontalInput(-1);
		else if (!pressed && m_moveLeft.isPressed())
			m_character.addHorizontalInput(1);
	}
	else if (code == m_moveUp.getCode())
	{
		if (pressed && !m_moveUp.isPressed())
			m_character.addVerticalInput(-1);
		else if (!pressed && m_moveUp.isPressed())
			m_character.addVerticalInput(1);
	}
	else if (code == m_moveDown.getCode())
	{
		if (pressed && !m_moveDown.isPressed())
			m_character.addVerticalInput(1);
		else if (!pressed && m_moveDown.isPressed())
			m_character.addVerticalInput(-1);
	}
	else if (code == m_sprint.getCode())
		m_character.setSprinting(pressed);

	if (code == m_moveRight.getCode())
		m_moveRight.setPressed(pressed);
	else if (code == m_moveLeft.getCode())
		m_moveLeft.setPressed(pressed);
	else if (code == m_moveUp.getCode())
		m_moveUp.setPressed(pressed);
	else if (code == m_moveDown.getCode())
		m_moveDown.setPressed(pressed);
	else if (code == m_sprint.getCode())
		m_character.setSprinting(pressed);
}