#include "Person.h"

#include <string>


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