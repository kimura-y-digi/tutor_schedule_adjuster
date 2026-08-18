#pragma once

#include <string>
#include <vector>

#include "Event.h"


class Person
{
public:
	Person(std::string name);
	int removeMeFromEvents(std::vector<Event>* related_events);

	int getId();
	void setId(int id);
	std::string getName();
	void setName(std::string name);
	std::string getEventsString();
	void setEventsFromString(std::string events);
	void addEvent(int event_id);
	void removeEvent(int event_id);
	static void updateMaxId(int max_id);

private:
	static int max_id;
	int id_;
	std::string name_;
	std::vector<int> events_;
};