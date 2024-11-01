#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <list>
#include <string>
#include <iostream>

#include "InputKey.hpp"

class InputHandler
{
	static InputHandler* instance;

	std::map<int, std::list<std::string>> m_keyMap
	{
		{sf::Keyboard::Scan::D, {"move_right"}},
		{sf::Keyboard::Scan::A, {"move_left"}},
		{sf::Keyboard::Scan::W, {"move_up"}},
		{sf::Keyboard::Scan::S, {"move_down"}},
		{sf::Keyboard::Scan::LShift, {"sprint"}},
		{sf::Keyboard::Scan::K, {"attack"}},
		{sf::Keyboard::Scan::Escape, {"close_game"}},
	};

	std::map<std::string, InputKey> m_keyStates;

	public:
		InputHandler(void);
		InputHandler(const InputHandler&) = delete;
		InputHandler& operator=(const InputHandler&) = delete;

		static InputHandler& getInstance()
		{
			if (!instance) {
				instance = new InputHandler();
			}
			return *instance;
		}

		void keyPressed(sf::Event::KeyEvent key);
		void keyReleased(sf::Event::KeyEvent key);

		bool isKeyPressed(std::string key);
};
