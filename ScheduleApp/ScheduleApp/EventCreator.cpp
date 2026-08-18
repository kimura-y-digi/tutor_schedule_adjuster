#include "EventCreator.h"

#include <iostream>
#include <vector>

#include "Event.h"
#include "InputHandler.h"
#include "Person.h"


EventCreator::EventCreator(std::vector<Person>* people, std::vector<Event>* events) 
	: people_(people), events_(events) {}

void EventCreator::run() {
	int outer_input = -1;
	
	while (true) {
		outer_input = choiceMethod();

		if (outer_input == 0) {
			break;
		}
		else if (outer_input == 1) {
			int inner_input = editEvent();

			if (inner_input == 9) {

			}
			else if (inner_input == 0) {

			}
			else {
				std::cerr << "意図しない入力です" << std::endl
					<< std::endl;
				break;
			}

			break;
		}
		else if (outer_input == 2) {
			Event event = editEventCondition();
			editEvent(event);
			break;
		}
		else {
			std::cerr << "意図しない入力です" << std::endl;
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

int EventCreator::editEvent(Event proposed) {
	InputHandler* input_handler = InputHandler::getInstance();

	int user_input = -1;
	while (true) {
		std::cout << "登録したい予定の情報を編集してください" << std::endl;

		std::cout << "[1]:名前 " << proposed.getName() << " を編集する" << std::endl
			<< "[2]:出席者 " << proposed.getParticipantsString() << " を編集する" << std::endl
			<< "[3]:開始日時 " << proposed.getStartDateTimeString() << " を編集する" << std::endl
			<< "[4]:終了日時 " << proposed.getEndDateTimeString() << " を編集する" << std::endl
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
			if (addEvent(proposed)) {
				std::cout << "予定の登録に成功しました"
					<< std::endl << std::endl;
				break;
			}
			else {
				std::cout << "予定の登録に失敗しました"
					<< std::endl << std::endl;
				continue;
			}
		}
		else if (user_input == 0) {
			proposed.setId(-1);
			break;
		}
		else {
			std::cerr << "意図しない入力です" << std::endl;
			continue;
		}
	}

	return user_input;
}

std::vector<int> EventCreator::pickParticipants() {
	return {};
}

bool EventCreator::addEvent(const Event& event) {
	return false;
}

Event EventCreator::editEventCondition() {
	EventCondition cd;
	Event event;
	std::vector<Event> events = collectEvents({});

	if (proposeEvent(cd, events, event)) {
		std::cout << "条件に合った予定が見つかりました" << std::endl
			<< "予定の登録に進みます" << std::endl
			<< std::endl;
	}
	return event;
}

std::vector<Event> EventCreator::collectEvents(std::vector<int> target_people) {
	std::vector<Event> collectEvents = {};
	Event event;
	collectEvents.push_back(event);
	return collectEvents;
}

bool EventCreator::proposeEvent(
	EventCondition cd,
	const std::vector<Event>& events,
	Event& out_event) {
	return false;
}