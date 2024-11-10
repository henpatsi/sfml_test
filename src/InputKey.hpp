#pragma once

#include <string>
#include <iostream>

class InputKey
{
	std::string m_name;
	int m_code;
	bool m_pressed = false;
	bool m_wasjustpressed = false;

	public:
		InputKey() : m_name(""), m_code(0) {};
		InputKey(std::string name, int code) : m_name(name), m_code(code) {};

		std::string getName() { return m_name; }
		int getCode() { return m_code; }
		bool isPressed() { return m_pressed; }
		bool wasJustPressed() { return m_wasjustpressed; }

		void setPressed(bool pressed);

		void update();
};
