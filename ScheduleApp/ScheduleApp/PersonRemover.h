#pragma once

#include <vector>

#include "Event.h"
#include "Person.h"


class PersonRemover
{
public:
	PersonRemover(std::vector<Person>* people, std::vector<Event>* events);

	void run();

private:
	int showPeople();
	int dispPersonDetail(int id);
	bool removePerson(int id);

	int current_page_;
	const int kMaxPerPage = 7;
	const int kInvalidId = -1;
	std::vector<Person>* people_;
	std::vector<Event>* events_;
};