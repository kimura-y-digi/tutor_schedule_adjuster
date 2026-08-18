#include "Event.h"

#include <chrono>
#include <iostream>
#include <string>

#include "Person.h"
#include "Util.h"


int Event::max_id = 0;

Event::Event() {
	++max_id;
	id_ = max_id;

	participants_.clear();
	start_datetime_ = std::chrono::sys_seconds::min();
	end_datetime_ = std::chrono::sys_seconds::min();
}

int Event::removeThisFromParticipants() {
	int num_remove = 0;
	return num_remove;
}

bool Event::hasEmpty() {
	if ( id_ < 0
			|| name_.empty()
			|| participants_.size() <= 0
			|| start_datetime_ == std::chrono::sys_seconds::min()
			|| end_datetime_ == std::chrono::sys_seconds::min()
		) {
		return true;
	}
	else {
		return false;
	}
}

int Event::getId() {
	return id_;
}

void Event::setId(int id) {
	id_ = id;
}

std::string Event::getName() {
	return name_;
}

void Event::setName(std::string name) {
	name_ = name;
}

std::string Event::getParticipantsString() {
	std::string ret;
	for (auto it = participants_.begin(); it != participants_.end(); ++it) {
		ret += *it;
		if (it != (participants_.end() - 1)) {
			ret += " ";
		}
	}

	return ret;
}

void Event::setParticipantFromString(std::string participants) {
	participants_.clear();
	try {
		std::istringstream iss(participants);
		std::string space_item;
		while (std::getline(iss, space_item, ' ')) {
			int person_id = std::stoi(space_item);
			participants_.push_back(person_id);
		}
	}
	catch (...) {
		std::cerr << "ERROR : Event::setParticipantFromString()" << std::endl;
	}
}

void Event::addParticipant(int person_id) {
	participants_.push_back(person_id);
}

void Event::removeParticipant(int person_id) {
	for (auto it = participants_.begin(); it != participants_.end(); ++it) {
		if (person_id == *it) {
			participants_.erase(it);
		}
	}
}

std::string Event::getStartDateTimeString() {
	return Util::sysSecondsToStr(start_datetime_);
}

void Event::setStartDateTime(std::string start_datetime) {
	start_datetime_ = Util::strToSysSeconds(start_datetime);
}

std::string Event::getEndDateTimeString() {
	return Util::sysSecondsToStr(end_datetime_);
}

void Event::setEndDateTime(std::string end_datetime) {
	end_datetime_ = Util::strToSysSeconds(end_datetime);
}

void Event::updateMaxId(int max_id) {
	max_id = max_id;
}