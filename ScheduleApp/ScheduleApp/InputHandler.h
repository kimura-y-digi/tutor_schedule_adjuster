#pragma once

#include <string>


class InputHandler
{
public:
	static InputHandler* getInstance();

	int receiveNumber(int max, int min = 0);
	std::string receiveString();

private:
	InputHandler() = default;

	InputHandler(InputHandler&) = delete;
	InputHandler& operator=(InputHandler&) = delete;
	InputHandler(InputHandler&&) = delete;
	InputHandler&& operator=(InputHandler&&) = delete;

	static InputHandler* instance;
};