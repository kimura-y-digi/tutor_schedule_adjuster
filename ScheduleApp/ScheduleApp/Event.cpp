#include "Event.h"

#include <chrono>
#include <string>

#include "Person.h"


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

std::string Event::getName() {
	return name_;
}

std::string Event::getParticipantsString() {
	std::string ret;
	for (auto it : participants_) {
		ret += it.getId();
		if (it.getId() != participants_.end()->getId()) {
			ret += " ";
		}
	}

	return ret;
}

std::string Event::getStartDateTimeString() {
	
}