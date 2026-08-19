#include "PersonCreator.h"

#include <iostream>
#include <string>
#include <vector>

#include "InputHandler.h"
#include "Person.h"


PersonCreator::PersonCreator(std::vector<Person>* people)
	: people_(people) {}

void PersonCreator::run() {
	InputHandler* input_handler = InputHandler::getInstance();
	
	std::string name;
	std::cout << "登録する名前を入力してください" << std::endl << std::endl;
	name = input_handler->receiveString();

	int input_num = -1;
	while (input_num == -1) {
		std::cout << name << " さんを登録して良いですか？" << std::endl << std::endl
			<< "[1]:登録    [0]:登録をやめる" << std::endl << std::endl;

		input_num = input_handler->receiveNumber(1);
	}

	if (input_num == 1) {
		people_->push_back(Person(name));
		std::cout << name << " さんを追加しました" << std::endl;
	}
	else if (input_num == 0) {
		std::cout << "登録をやめました" << std::endl;
	}

	std::cout << std::endl << std::endl;
}