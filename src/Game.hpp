#pragma once

#include <SFML/Graphics.hpp>

#include "Character.hpp"
#include "InputKey.hpp"

class Game
{
	Character m_character;

	InputKey m_moveRight = InputKey("move_right", sf::Keyboard::Scan::D);
	InputKey m_moveLeft = InputKey("move_left", sf::Keyboard::Scan::A);
	InputKey m_moveUp = InputKey("move_up", sf::Keyboard::Scan::W);
	InputKey m_moveDown = InputKey("move_down", sf::Keyboard::Scan::S);

	public:

		void update(float delta);
		void input(int code, bool pressed);
};
