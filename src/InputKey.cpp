#include "InputKey.hpp"

void InputKey::setPressed(bool pressed)
{
	m_pressed = pressed;

	if (pressed && !m_wasjustpressed)
	{
		m_wasjustpressed = true;
	}
}

void InputKey::update()
{
	m_wasjustpressed = false;
}