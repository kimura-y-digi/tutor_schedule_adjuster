#include "EventCreator.h"

#include <iostream>
#include <vector>

#include "Event.h"
#include "InputHandler.h"
#include "Person.h"
#include "Util.h"


EventCreator::EventCreator(std::vector<Person>* people, std::vector<Event>* events) 
	: people_(people), events_(events), mode_(Mode::kChoiceMethod) {}

void EventCreator::run() {
	mode_ = Mode::kChoiceMethod;
	EventCondition condition;
	Event event;

	int user_input = -1;
	bool go_next = false;
	while (true) {
		if (mode_ == Mode::kTerminate) {
			break;
		}

		switch (mode_) {
		case Mode::kChoiceMethod:
			user_input = choiceMethod();
			if (user_input == 0) {
				mode_ = Mode::kTerminate;
			}
			else if (user_input == 1) {
				mode_ = Mode::kEditEvent;
			}
			else if (user_input == 2) {
				mode_ = Mode::kEditCondition;
			}
			break;

		case Mode::kEditEvent:
			go_next = editEvent(event);
			if (go_next) {
				mode_ = Mode::kConfirmRegistEvent;
			}
			else {
				mode_ = Mode::kChoiceMethod;
			}
			break;

		case Mode::kConfirmRegistEvent:
			go_next = confirmRegistEvent(event);
			if (go_next) {
				bool is_success = addEvent(event);
				if (is_success) {
					mode_ = Mode::kTerminate;
				}
				else {
					mode_ = Mode::kEditEvent;
				}
			}
			else {
				mode_ = Mode::kEditEvent;
			}
			break;

		case Mode::kEditCondition:
			go_next = editEventCondition(condition);
			if (go_next) {
				bool is_find = proposeEvent(condition, event);
				if (is_find) {
					mode_ = Mode::kConfirmProposedEvent;
				}
				else {
					mode_ = Mode::kEditCondition;
				}
			}
			else {
				mode_ = Mode::kChoiceMethod;
			}
			break;

		case Mode::kConfirmProposedEvent:
			go_next = confirmProposedEvent(event);
			if (go_next) {
				mode_ = Mode::kEditEvent;
			}
			else {
				mode_ = Mode::kEditCondition;
			}
			break;

		default:
			std::cerr << "エラーが発生しました" << std::endl
				<< "予定登録を終了します" << std::endl << std::endl;
			mode_ = Mode::kTerminate;
			break;
		}
	}
}

int EventCreator::choiceMethod() {
	InputHandler* input_handler = InputHandler::getInstance();

	int user_input = -1;
	while (true) {
		std::cout << "予定の登録をします。" << std::endl;
		std::cout << "登録方法を選択してください。"
			<< std::endl << std::endl;

		std::cout << "[1]:新規で登録 [2]:条件から提案して登録" << std::endl
			<< "[0]:予定の登録をやめる" << std::endl << std::endl;

		user_input = input_handler->receiveNumber(2);

		if (0 <= user_input && user_input <= 2) {
			break;
		}
	}

	return user_input;
}

bool EventCreator::editEvent(Event& event) {
	InputHandler* input_handler = InputHandler::getInstance();

	bool go_next = false;
	int user_input = -1;
	while (true) {
		std::cout << "登録したい予定の情報を編集してください" << std::endl << std::endl;

		std::cout << "[1]:名前 " << event.getName() << " を編集する" << std::endl
			<< "[2]:出席者 " << event.getParticipantsString() << " を編集する" << std::endl
			<< "[3]:開始日時 " << event.getStartDateTimeString() << " を編集する" << std::endl
			<< "[4]:終了日時 " << event.getEndDateTimeString() << " を編集する" << std::endl
			<< std::endl;

		std::cout << "[9]:この予定を登録する  [0]:登録方法の選択に戻る" << std::endl
			<< std::endl;

		user_input = input_handler->receiveNumberAllowNine(4);

		if (user_input == 1) {
			continue;
		}
		else if (user_input == 2) {
			continue;
		}
		else if (user_input == 3) {
			continue;
		}
		else if (user_input == 4) {
			continue;
		}
		else if (user_input == 9) {
			if (!event.hasEmpty()) {
				go_next = true;
				break;
			}
			else {
				std::cout << "未入力の項目があります" << std::endl
					<< std::endl << std::endl;
				continue;
			}
		}
		else if (user_input == 0) {
			event.setId(-1);
			break;
		}
	}

	return go_next;
}

bool EventCreator::confirmRegistEvent(const Event& event) {
	InputHandler* input_handler = InputHandler::getInstance();

	int user_input = -1;
	while (true) {
		std::cout << "こちらの予定を登録します" << std::endl << std::endl;

		std::cout << "名前 : " << event.getName() << std::endl
			<< "出席者 : " << event.getParticipantsString() << std::endl
			<< "開始日時 : " << event.getStartDateTimeString() << std::endl
			<< "終了日時 : " << event.getEndDateTimeString() << std::endl
			<< std::endl;

		std::cout << "[1]:登録する  [0]:予定の編集に戻る"
			<< std::endl << std::endl;

		user_input = input_handler->receiveNumber(1);
		if (user_input == 0 || user_input == 1) {
			break;
		}
	}

	if (user_input == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool EventCreator::addEvent(const Event& event) {
	events_->push_back(event);

	int add_count = 0;
	for (int participant_id : event.getParticipants()) {
		for (Person& person : *people_) {
			if (person.getId() == participant_id) {
				person.addEvent(event.getId());
				++add_count;
				break;
			}
		}
	}

	return add_count == (event.getParticipants()).size();
}

bool EventCreator::editEventCondition(EventCondition& condition) {
	InputHandler* input_handler = InputHandler::getInstance();

	bool go_next = false;
	int user_input = -1;
	while (true) {
		std::cout << "予定の提案に必要な情報を編集してください" << std::endl;

		std::cout << "[1]:予定の所要時間 " << condition.use_minutes << " を編集する" << std::endl
			<< "[2]:出席予定の人 " << Util::vectorIntToStr(condition.participants) 
				<< " を編集する" << std::endl
			<< "[3]:検索の開始日 " << condition.start_date << " を編集する" << std::endl
			<< "[4]:検索の終了日 " << condition.end_date << " を編集する" << std::endl
			<< "[5]:検索の開始日 " << condition.start_time << " を編集する" << std::endl
			<< "[6]:検索の終了日 " << condition.end_time << " を編集する" << std::endl
			<< std::endl;

		std::cout << "[9]:この条件で提案に進む  [0]:予定の登録方法の選択に戻る" << std::endl
			<< std::endl;

		user_input = input_handler->receiveNumberAllowNine(6);

		if (user_input == 1) {
			continue;
		}
		else if (user_input == 2) {
			continue;
		}
		else if (user_input == 3) {
			continue;
		}
		else if (user_input == 4) {
			continue;
		}
		else if (user_input == 5) {
			continue;
		}
		else if (user_input == 6) {
			continue;
		}
		else if (user_input == 9) {
			go_next = true;
			break;
		}
		else if (user_input == 0) {
			break;
		}
	}

	return go_next;
}

bool EventCreator::proposeEvent(const EventCondition& condition, Event& event) {
	return true;
}

bool EventCreator::confirmProposedEvent(const Event& event) {
	InputHandler* input_handler = InputHandler::getInstance();

	int user_input = -1;
	while (true) {
		std::cout << "こちらの予定が提案されました" << std::endl << std::endl;

		std::cout << "名前 : " << event.getName() << std::endl
			<< "出席者 : " << event.getParticipantsString() << std::endl
			<< "開始日時 : " << event.getStartDateTimeString() << std::endl
			<< "終了日時 : " << event.getEndDateTimeString() << std::endl
			<< std::endl;

		std::cout << "[1]:予定の登録に進む  [0]:予定の提案に戻る"
			<< std::endl << std::endl;

		user_input = input_handler->receiveNumber(1);
		if (user_input == 0 || user_input == 1) {
			break;
		}
	}

	if (user_input == 1) {
		return true;
	}
	else {
		return false;
	}
}

std::vector<int> EventCreator::pickParticipants() {
	return {};
}

std::vector<Event> EventCreator::collectEvents(std::vector<int> target_people) {
	std::vector<Event> collectEvents = {};
	Event event;
	collectEvents.push_back(event);
	return collectEvents;
}