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

int InputHandler::receiveNumber(int max, int min) {
	std::string input;
	int value = -1;

	std::cout << "> ";
	try {
		std::cin >> input;
		value = std::stoi(input);

		std::system("cls");
		if (value < min || max < value) {
			std::system("cls");
			std::cerr << min << " ～ " << max
				<< " の間で入力してください" << std::endl;
			std::cout << std::endl << std::endl;
			value = -1;
		}
	}
	catch (...) {
		std::system("cls");
		std::cerr << "数字で入力してください" << std::endl;
		std::cout << std::endl << std::endl;
	}

	return value;
}

int InputHandler::receiveNumberAllowNine(int max, int min) {
	std::string input;
	int value = -1;

	std::cout << "> ";
	try {
		std::cin >> input;
		value = std::stoi(input);

		std::system("cls");
		if ((value < min || max < value) && (value != 9)) {
			std::system("cls");
			std::cerr << min << " ～ " << max
				<< " の間か、9 で入力してください" << std::endl;
			std::cout << std::endl << std::endl;
			value = -1;
		}
	}
	catch (...) {
		std::system("cls");
		std::cerr << "数字で入力してください" << std::endl;
		std::cout << std::endl << std::endl;
	}

	return value;
}

std::string InputHandler::receiveString() {
	std::string input;

	std::cout << "> ";
	try {
		std::cin >> input;
		std::system("cls");
	}
	catch (...) {
		std::system("cls");
		std::cerr << "入力値のエラー" << std::endl;
		std::cout << std::endl << std::endl;
	}

	return input;
}