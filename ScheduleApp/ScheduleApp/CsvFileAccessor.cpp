#include "CsvFileAccessor.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "InputHandler.h"
#include "Person.h"


CsvFileAccessor::CsvFileAccessor(
	std::vector<Person>* people,
	std::vector<Event>* events)
	: kPersonFilePath("persons.csv"), kEventFilePath("events.csv"),
		kDelim(','), people_(people), events_(events) {}

bool CsvFileAccessor::writeFiles() {
	InputHandler* input_handler = InputHandler::getInstance();

	int user_input = -1;
	while (user_input == -1) {
		std::cout << "人と予定のデータをファイルに保存します" << std::endl << std::endl;
		std::cout << "[1]:保存する [0]:保存をやめる" << std::endl << std::endl;

		user_input = input_handler->receiveNumber(1);
	}

	bool is_success = false;
	if (user_input == 1) {
		bool is_success_people = writePerson();
		bool is_success_events = writeEvents();
		if (is_success_people && is_success_events) {
			is_success = true;
		}
	}

	return is_success;
}

bool CsvFileAccessor::readFiles() {
	InputHandler* input_handler = InputHandler::getInstance();

	int user_input = -1;
	while (user_input == -1) {
		std::cout << "人と予定のデータをファイルを読込します" << std::endl << std::endl;
		std::cout << "[1]:読込する [0]:読込をやめる" << std::endl << std::endl;

		user_input = input_handler->receiveNumber(1);
	}

	bool is_success = false;
	if (user_input == 1) {
		bool is_success_people = readPerson();
		bool is_success_events = readEvents();
		if (is_success_people && is_success_events) {
			is_success = true;
		}
	}

	return is_success;
}

bool CsvFileAccessor::writePerson() {
	bool is_success = false;

	try {
		std::ofstream file(kPersonFilePath);
		file << "id,name,events" << std::endl;
		for(auto it : *people_) {
			file << it.getId() << ","
				<< it.getName() << ","
				<< it.getEventsString() 
				<< std::endl;
		}

		file.close();
		is_success = true;
	}
	catch (...) {
		std::cerr << "人の情報の保存に失敗しました" << std::endl << std::endl;
	}

	return is_success;
}

bool CsvFileAccessor::writeEvents() {
	bool is_success = false;

	try {
		std::ofstream file(kEventFilePath);
		file << "id,name,participants,start_datetime,end_datetime" << std::endl;
		for (auto it : *events_) {
			file << it.getId() << ","
				<< it.getName() << ","
				<< it.getParticipantsString() << ","
				<< it.getStartDateTimeString() << ","
				<< it.getEndDateTimeString()
				<< std::endl;
		}

		file.close();
		is_success = true;
	}
	catch (...) {
		std::cerr << "人の情報の保存に失敗しました" << std::endl << std::endl;
	}

	return is_success;
}

bool CsvFileAccessor::readPerson() {
	bool is_success = false;

	try {
		people_->clear();

		std::ifstream file(kPersonFilePath);
		std::string line;
		std::string csv_item;
		int max_id = 0;
		std::getline(file, line);  // skip header
		while (std::getline(file, line)) {
			Person person("");
			std::istringstream line_iss(line);

			std::getline(line_iss, csv_item, kDelim);
			int person_id = std::stoi(csv_item);
			person.setId(person_id);
			if (person_id > max_id) {
				max_id = person_id;
			}

			std::getline(line_iss, csv_item, kDelim);
			person.setName(csv_item);

			std::getline(line_iss, csv_item, kDelim);
			person.setEventsFromString(csv_item);

			people_->push_back(person);
		}

		file.close();
		Person::updateMaxId(max_id);
		is_success = true;
	}
	catch (...) {
		std::cerr << "人の情報の読込に失敗しました" << std::endl << std::endl;
	}

	return is_success;
}

bool CsvFileAccessor::readEvents() {
	bool is_success = false;

	try {
		events_->clear();

		std::ifstream file(kEventFilePath);
		std::string line;
		std::string csv_item;
		int max_id = 0;
		std::getline(file, line);  // skip header
		while (std::getline(file, line)) {
			Event event;
			std::istringstream line_iss(line);

			std::getline(line_iss, csv_item, kDelim);
			int event_id = std::stoi(csv_item);
			event.setId(event_id);
			if (event_id > max_id) {
				max_id = event_id;
			}

			std::getline(line_iss, csv_item, kDelim);
			event.setName(csv_item);

			std::getline(line_iss, csv_item, kDelim);
			event.setParticipantFromString(csv_item);

			std::getline(line_iss, csv_item, kDelim);
			event.setStartDateTime(csv_item);
			event.setEndDateTime(csv_item);

			events_->push_back(event);
		}

		file.close();
		Event::updateMaxId(max_id);
		is_success = true;
	}
	catch (...) {
		std::cerr << "予定の情報の読込に失敗しました" << std::endl << std::endl;
	}

	return is_success;
}