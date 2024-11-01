#pragma once

#include <string>

class InputKey
{
	std::string m_name;
	int m_code;
	bool m_pressed = false;

	public:
		InputKey() : m_name(""), m_code(0) {};
		InputKey(std::string name, int code) : m_name(name), m_code(code) {};

		std::string getName() { return m_name; }
		int getCode() { return m_code; }
		bool isPressed() { return m_pressed; }

		void setPressed(bool pressed) { m_pressed = pressed; }
};
