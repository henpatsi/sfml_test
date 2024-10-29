#pragma once

#include <iostream>

class Character
{
	int m_health = 100;
	int m_stamina = 100;
	int m_move_speed = 10;

	int m_horizontal_input = 0;
	int m_vertical_input = 0;

	float m_x_pos = 0;
	float m_y_pos = 0;

	public:
		Character(void) {};

		void addHorizontalInput(int x) { m_horizontal_input += x; }
		void addVerticalInput(int y) { m_vertical_input += y; }

		void update(float delta);
};
