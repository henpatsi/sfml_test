#pragma once

#include <SFML/Graphics.hpp>

#include "Character.hpp"

#define FPS_FONT_PATH "assets/fonts/Atop-R99O3.ttf"

class Game
{
	Character m_character;

	// FPS

	sf::Font m_font;
	sf::Text m_FPSText;

	public:
		Game(void);

		void update(float delta);
		void render(sf::RenderWindow& window);
};
