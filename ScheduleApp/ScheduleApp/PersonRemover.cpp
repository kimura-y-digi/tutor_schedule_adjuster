#include "PersonRemover.h"

#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

#include "Event.h"
#include "InputHandler.h"
#include "Person.h"


PersonRemover::PersonRemover(std::vector<Person>* people, std::vector<Event>* events) 
	: people_(people), events_(events), current_page_(1) {}

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

			std::map<int, int> inputToId = {};
			int initial_index = (current_page_ - 1) * kMaxPerPage;
			int select_num = 3;
			for (int i = initial_index;
					(i < people_->size()) && (i < current_page_ * kMaxPerPage);
					++i) {
				std::cout << "[" << select_num << "] : "
					<< people_->at(i).getName() << std::endl;
				inputToId.insert(std::make_pair(select_num, people_->at(i).getId()));
				++select_num;
			}

			int max_page = static_cast<int>(
				std::ceil(people_->size() / static_cast<double>(kMaxPerPage))
			);
			std::cout << "表示ページ " << current_page_ << "/" << max_page << std::endl;
			std::cout << "[1]:前のページ [2]次のページ" << std::endl
				<< "[0]:削除をやめる" << std::endl << std::endl;

			int max_select = people_->size() % kMaxPerPage;
			if (max_select == 0) {
				max_select = kMaxPerPage;
			}
			max_select += 2;
			int user_input = input_handler->receiveNumber(max_select);

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
			else if (3 <= user_input && user_input <= max_select) {
				int selected_id = inputToId.at(user_input);
				return selected_id;
			}
		}
	}
}

int PersonRemover::dispPersonDetail(int id) {
	InputHandler* input_handler = InputHandler::getInstance();
	
	Person person("");
	for (auto it = people_->begin(); it != people_->end(); ++it) {
		if (id == it->getId()) {
			person.setName(it->getName());  // deep copy
			break;
		}
	}

	std::cout << "こちらの人を削除します" << std::endl;
	std::cout << "名前 : " << person.getName()
		<< std::endl << std::endl;

	std::cout << "[1]:削除する [0]:削除をやめる" << std::endl << std::endl;
	int user_input = input_handler->receiveNumber(1);

	return user_input;
}

bool PersonRemover::removePerson(int id) {
	bool success = false;
	for (auto it = people_->begin(); it != people_->end(); ++it) {
		if (id == it->getId()) {
			std::vector<Event> related_events = {};
			std::copy_if(
				events_->begin(),
				events_->end(),
				std::back_inserter(related_events),
				[id](Event event) { return event.hasPerson(id); }
			);

			it->removeMeFromEvents(&related_events);
			people_->erase(it);
			success = true;
			break;
		}
	}

	return success;
}