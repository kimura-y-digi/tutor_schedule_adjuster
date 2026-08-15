#include "PersonRemover.h"

#include <stdlib.h>

#include <iostream>
#include <cmath>
#include <vector>

#include "InputHandler.h"
#include "Person.h"


PersonRemover::PersonRemover(std::vector<Person>* people) 
	: people_(people) , current_page_(1) {}

void PersonRemover::run() {
	while (true) {
		int remove_id = showPeople();
		if (remove_id == kInvalidId) {
			break;
		}
		else {
			int selected_num = dispPersonDetail(remove_id);
			if (selected_num == 1) {
				removePerson(remove_id);
				break;
			}
			else {
				continue;
			}
		}
	}
}

int PersonRemover::showPeople() {
	if (people_->size() <= 0) {
		std::cout << "登録されている人はいません" << std::endl << std::endl;
		system("pause");
		system("cls");

		return kInvalidId;
	}
	else {
		InputHandler* input_handler = InputHandler::getInstance();

		while (true) {
			std::cout << "削除したい人の番号 [ ] を選択してください"
				<< std::endl << std::endl;

			int initial_index = (current_page_ - 1) * kMaxPerPage;
			int select_num = 3;
			for (int i = initial_index;
					(i < people_->size()) && (i < current_page_ * kMaxPerPage);
					++i) {
				std::cout << "[" << select_num << "] : "
					<< people_->at(i).getName() << std::endl;
				++select_num;
			}

			int max_page = std::ceil(people_->size() / static_cast<double>(kMaxPerPage));
			std::cout << "表示ページ " << current_page_ << "/" << max_page << std::endl;
			std::cout << "[1]:前のページ [2]次のページ" << std::endl
				<< "[0]:削除をやめる" << std::endl << std::endl;

			int user_input = input_handler->receiveNumber(9);

			if (user_input == 0) {
				return kInvalidId;
			}
			else if (user_input == 1) {
				--current_page_;
				if (current_page_ <= 0) {
					current_page_ = max_page;
				}
				continue;
			}
			else if (user_input == 2) {
				++current_page_;
				if (current_page_ > max_page) {
					current_page_ = 1;
				}
				continue;
			}
			else if (3 <= user_input && user_input <= 9) {
				int selected_id = 0;
				return selected_id;
			}
			else {
				std::cerr << "意図しない入力です" << std::endl;
				continue;
			}

		}
	}
}

int PersonRemover::dispPersonDetail(int id) {
	InputHandler* input_handler = InputHandler::getInstance();
	
	// 情報表示

	// 選択肢表示

	int user_input = input_handler->receiveNumber(1);

	return user_input;
}

bool PersonRemover::removePerson(int id) {
	return false;
}