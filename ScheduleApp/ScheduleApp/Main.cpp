#include <iostream>
#include <string>
#include <vector>

#include "CsvFileAccessor.h"
#include "Event.h"
#include "InputHandler.h"
#include "Person.h"
#include "PersonCreator.h"
#include "PersonRemover.h"


int main() {
	std::vector<Person> people{};
	std::vector<Event> events{};

	InputHandler* input_handler = InputHandler::getInstance();
	PersonCreator person_creator(&people);
	PersonRemover person_remover(&people, &events);
	CsvFileAccessor csv_file_accessor(&people, &events);

	int input_num = -1;
	while (true) {
		std::cout << "  日程調整ソフトウェア  " << std::endl
			<< "[ ] に書かれた数字を入力して、機能を選択してください" 
			<< std::endl << std::endl;
		std::cout << "[1]:人の登録 [2]:人の削除" << std::endl
			<< "[3]:予定の登録 [4]:予定の削除" << std::endl
			<< "[5]:ファイルへ保存 [6]:ファイルの読込" << std::endl
			<< "[0]:終了" << std::endl << std::endl;
		input_num = input_handler->receiveNumber(6);

		if (input_num == 0) {
			break;
		}
		else if (input_num == 1) {
			person_creator.run();
			continue;
		}
		else if (input_num == 2) {
			person_remover.run();
			continue;
		}
		else if (input_num == 3) {
			continue;
		}
		else if (input_num == 4) {
			continue;
		}
		else if (input_num == 5) {
			csv_file_accessor.writeFiles();
			continue;
		}
		else if (input_num == 6) {
			csv_file_accessor.readFiles();
			continue;
		}
		else {
			continue;
		}
	}

	std::cout << "終了します" << std::endl;
	return 0;
}