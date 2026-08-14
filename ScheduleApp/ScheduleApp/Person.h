#pragma once

#include <string>
#include <vector>

#include "Event.h"


class Event;

class Person
{
public:
	Person(std::string name);
	int removeMeFromEvents();

private:
	static int max_id;
	int id_;
	std::string name_;
	std::vector<Event> events_;

};

