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

/*
 * receiveNumber関数
 * 
 * 引数 : min ～ max の範囲で入力を受け付ける
 * 戻り値 : エラーが発生した際は -1 を返す
 * 
 * 補足 : 入力受付をした後に画面のクリアを実行する
 *        エラーメッセージは残したいため、画面クリア後に表示する
 *        そのため、元々の選択肢表示を改めて表示する必要がある
 *        使われ方として、return -1 があった際は再度呼び出しされることを想定
 * 
 * メモ : 表示したい文字列を引数で貰えば、欲しい入力が取れるまでループができる
 */
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