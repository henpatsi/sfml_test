#pragma once

#include <SFML/Graphics.hpp>

#include "Character.hpp"
#include "InputKey.hpp"

#define FPS_FONT_PATH "assets/fonts/Atop-R99O3.ttf"

class Game
{
	Character m_character;

	// Input

	InputKey m_moveRight = InputKey("move_right", sf::Keyboard::Scan::D);
	InputKey m_moveLeft = InputKey("move_left", sf::Keyboard::Scan::A);
	InputKey m_moveUp = InputKey("move_up", sf::Keyboard::Scan::W);
	InputKey m_moveDown = InputKey("move_down", sf::Keyboard::Scan::S);
	InputKey m_sprint = InputKey("sprint", sf::Keyboard::Scan::LShift);

	// FPS

	sf::Font m_font;
	sf::Text m_FPSText;

	public:
		Game(void);

		void update(float delta);
		void render(sf::RenderWindow& window);
		void input(int code, bool pressed);
};
