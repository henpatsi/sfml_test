#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <list>

#include "InputKey.hpp"

class InputHandler
{

	std::map<int, std::list<std::string>> m_keyMap
	{
		{sf::Keyboard::Scan::D, {"move_right"}},
		{sf::Keyboard::Scan::A, {"move_left"}},
		{sf::Keyboard::Scan::W, {"move_up"}},
		{sf::Keyboard::Scan::S, {"move_down"}},
		{sf::Keyboard::Scan::LShift, {"sprint"}},
		{sf::Keyboard::Scan::Escape, {"close_game"}},
	};

	// TODO just make this automatically generated based on keyMap
	// std::map<std::string, InputKey> m_keyStates {
	// 	{"move_right", InputKey("move_right", sf::Keyboard::Scan::D)},
	// 	{"move_left", InputKey("move_left", sf::Keyboard::Scan::A)},
	// 	{"move_up", InputKey("move_up", sf::Keyboard::Scan::W)},
	// 	{"move_down", InputKey("move_down", sf::Keyboard::Scan::S)},
	// 	{"sprint", InputKey("sprint", sf::Keyboard::Scan::LShift)},
	// 	{"close_game", InputKey("close_game", sf::Keyboard::Scan::Escape)},
	// };

	public:
		InputHandler(void) {};

		void keyPressed(sf::Event::KeyEvent key);
		void keyReleased(sf::Event::KeyEvent key);

		bool isKeyPressed(std::string key);
};
