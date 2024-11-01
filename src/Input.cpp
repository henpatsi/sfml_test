#include "Input.hpp"

void Input::keyPressed(sf::Event::KeyEvent keyEvent)
{
	for (std::string keyName : m_keyMap[keyEvent.code])
	{
		m_keyStates[keyName].setPressed(true);
	}
}

void Input::keyReleased(sf::Event::KeyEvent keyEvent)
{
	for (std::string keyName : m_keyMap[keyEvent.code])
	{
		m_keyStates[keyName].setPressed(false);
	}
}

bool Input::isKeyPressed(std::string key)
{
	return m_keyStates[key].isPressed();
}