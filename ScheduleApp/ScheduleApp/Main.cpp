#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "InputHandler.h"
#include "Person.h"
#include "PersonCreator.h"


int main() {
	std::vector<Person> people{};
	std::vector<Event> events{};

	InputHandler* inputHandler = InputHandler::getInstance();
	PersonCreator person_creator(&people);

	int inputNum = -1;
	while (true) {
		std::cout << "  日程調整ソフトウェア  " << std::endl
			<< "[ ] に書かれた数字を入力して、機能を選択してください" 
			<< std::endl << std::endl;
		std::cout << "[1]:人の登録 [2]:人の削除" << std::endl
			<< "[3]:予定の登録 [4]:予定の削除" << std::endl
			<< "[5]:ファイルへ保存 [6]:ファイルの読込" << std::endl
			<< "[0]:終了" << std::endl << std::endl;
		inputNum = inputHandler->receiveNumber(6);

		if (inputNum == 0) {
			break;
		}
		else if (inputNum == 1) {
			person_creator.run();
			continue;
		}
		else if (inputNum == 2) {
			continue;
		}
		else if (inputNum == 3) {
			continue;
		}
		else if (inputNum == 4) {
			continue;
		}
		else if (inputNum == 5) {
			continue;
		}
		else if (inputNum == 6) {
			continue;
		}
		else {
			continue;
		}
	}

	std::cout << "終了します" << std::endl;
	return 0;
}