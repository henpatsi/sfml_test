#include "Character.hpp"

void Character::update(float delta)
{
	if (m_horizontal_input != 0)
	{
		m_x_pos += m_horizontal_input * m_move_speed * delta;
	}

	if (m_vertical_input != 0)
	{
		m_y_pos += m_vertical_input * m_move_speed  * delta;
	}

	if (m_horizontal_input != 0 || m_vertical_input != 0)
	{
		std::cout << "x input: " << m_horizontal_input << std::endl;
		std::cout << "y input: " << m_vertical_input << std::endl;
		std::cout << "delta: " << delta << std::endl;
		std::cout << "pos: " << m_x_pos << ", " << m_y_pos << std::endl;
	}
}