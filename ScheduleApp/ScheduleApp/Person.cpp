#include "Person.h"

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"


int Person::max_id = 0;

Person::Person(std::string name) : name_(name) {
	++max_id;
	id_ = max_id;
	events_.clear();
}

int Person::removeMeFromEvents() {
	int num_remove = 0;
	return num_remove;
}

int Person::getId() {
	return id_;
}

void Person::setId(int id) {
	id_ = id;
}

std::string Person::getName() {
	return name_;
}

void Person::setName(std::string name) {
	name_ = name;
}

std::string Person::getEventsString() {
	std::string ret;
	for (auto it = events_.begin(); it != events_.end(); ++it) {
		ret += *it;
		if (it != (events_.end() - 1)) {
			ret += " ";
		}
	}

	return ret;
}

void Person::setEventsFromString(std::string events) {
	events_.clear();
	try {
		std::istringstream iss(events);
		std::string space_item;
		while (std::getline(iss, space_item, ' ')) {
			int event_id = std::stoi(space_item);
			events.push_back(event_id);
		}
	}
	catch (...) {
		std::cerr << "ERROR : Person::setEventsFromString()" << std::endl;
	}
}

void Person::addEvent(int event_id) {
	events_.push_back(event_id);
}

void Person::removeEvent(int event_id) {
	for (auto it = events_.begin(); it != events_.end(); ++it) {
		if (event_id == *it) {
			events_.erase(it);
		}
	}
}

void Person::updateMaxId(int max_id) {
	max_id = max_id;
}