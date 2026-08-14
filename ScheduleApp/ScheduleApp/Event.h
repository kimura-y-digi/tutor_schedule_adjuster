#pragma once

#include <chrono>
#include <string>
#include <vector>

#include "Person.h"


class Person;

class Event
{
public:
	Event();
	int removeThisFromParticipants();

	bool hasEmpty();

private:
	static int max_id;
	int id_;
	std::string name_;
	std::vector<Person> participants_;
	std::chrono::sys_seconds start_datetime_;
	std::chrono::sys_seconds end_datetime_;
};

