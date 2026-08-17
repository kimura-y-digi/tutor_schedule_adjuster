#include "Person.h"

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
	for (auto it : events_) {
		ret += it.getId();
		if (it.getId() != events_.end()->getId()) {
			ret += " ";
		}
	}

	return ret;
}