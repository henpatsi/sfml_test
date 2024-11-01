#include "InputHandler.hpp"

void InputHandler::keyPressed(sf::Event::KeyEvent keyEvent)
{
	for (std::string keyName : m_keyMap[keyEvent.code])
	{
		return; //m_keyStates[keyName].setPressed(true);
	}
}

void InputHandler::keyReleased(sf::Event::KeyEvent keyEvent)
{
	for (std::string keyName : m_keyMap[keyEvent.code])
	{
		return; //m_keyStates[keyName].setPressed(false);
	}
}

bool InputHandler::isKeyPressed(std::string key)
{
	return true;// m_keyStates[key].isPressed();
}