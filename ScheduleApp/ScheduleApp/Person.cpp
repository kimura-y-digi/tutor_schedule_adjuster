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

std::string Person::getName() {
	return name_;
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