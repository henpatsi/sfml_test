#include "InputKey.hpp"

void InputKey::setPressed(bool pressed)
{
	m_pressed = pressed;

	if (pressed && !m_wasjustpressed)
	{
		std::cout << "Key " << m_name << " was just pressed" << std::endl;
		m_wasjustpressed = true;
	}
}

void InputKey::update()
{
	m_wasjustpressed = false;
}