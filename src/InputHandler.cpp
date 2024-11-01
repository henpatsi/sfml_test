#include "InputHandler.hpp"

InputHandler* InputHandler::instance = nullptr;

InputHandler::InputHandler()
{
	for (auto key : m_keyMap)
	{
		for (std::string keyName : key.second)
		{
			m_keyStates[keyName] = InputKey(keyName, key.first);
			std::cout << "Key: " << keyName << " Code: " << key.first << std::endl;
		}
	}
}

void InputHandler::keyPressed(sf::Event::KeyEvent keyEvent)
{
	for (std::string keyName : m_keyMap[keyEvent.scancode])
	{
		m_keyStates[keyName].setPressed(true);
	}
}

void InputHandler::keyReleased(sf::Event::KeyEvent keyEvent)
{
	for (std::string keyName : m_keyMap[keyEvent.scancode])
	{
		m_keyStates[keyName].setPressed(false);
	}
}

bool InputHandler::isKeyPressed(std::string key)
{
	return m_keyStates[key].isPressed();
}