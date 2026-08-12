#include "InputHandler.h"

#include <iostream>
#include <string>


InputHandler* InputHandler::instance = nullptr;

InputHandler* InputHandler::getInstance() {
	if (instance == nullptr) {
		instance = new InputHandler();
	}

	return instance;
}

int InputHandler::receiveNumber() {
	std::string input;
	int value = -1;
	try {
		std::cin >> input;
		value = std::stoi(input);
	}
	catch (...) {
		std::cerr << "数字で入力してください" << std::endl;
	}

	return value;
}

std::string InputHandler::receiveString() {
	std::string input;

	try {
		std::cin >> input;
	}
	catch (...) {
		std::cerr << "入力値のエラー" << std::endl;
	}

	return input;
}