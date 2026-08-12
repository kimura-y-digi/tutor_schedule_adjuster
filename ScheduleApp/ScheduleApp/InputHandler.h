#pragma once

#include <string>


class InputHandler
{
private:
	static InputHandler* instance;
	
	InputHandler() = default;

	InputHandler(InputHandler&) = delete;
	InputHandler& operator=(InputHandler&) = delete;
	InputHandler(InputHandler&&) = delete;
	InputHandler&& operator=(InputHandler&&) = delete;

public:
	static InputHandler* getInstance();
	int receiveNumber();
	std::string receiveString();
};

