#include "PersonCreator.h"

#include <iostream>
#include <string>
#include <vector>

#include "InputHandler.h"
#include "Person.h"


PersonCreator::PersonCreator(std::vector<Person>* people)
	: people_(people) {}

void PersonCreator::run() {
	InputHandler* inputHandler = InputHandler::getInstance();
	
	std::string name;
	std::cout << "登録する名前を入力してください" << std::endl << std::endl;
	name = inputHandler->receiveString();

	int inputNum = -1;
	while (inputNum == -1) {
		std::cout << name << " さんを登録して良いですか？" << std::endl << std::endl
			<< "[1]:登録    [0]:登録をキャンセル" << std::endl << std::endl;

		inputNum = inputHandler->receiveNumber(1);
	}

	if (inputNum == 1) {
		people_->push_back(Person(name));
		std::cout << name << " さんを追加しました" << std::endl;
	}
	else if (inputNum == 0) {
		std::cout << "キャンセルしました" << std::endl;
	}
	else {
		std::cerr << "意図しない入力です" << std::endl;
	}

	std::cout << std::endl << std::endl;
}