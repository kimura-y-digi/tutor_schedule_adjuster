#pragma once

#include <vector>

#include "Person.h"


class PersonRemover
{
public:
	PersonRemover(std::vector<Person>* people);

	void run();

private:
	void showPeople();
	void dispPersonDetail(int id);
	bool removePerson(int id);

	int current_page_;
	const int kMaxPerPage = 7;
	std::vector<Person>* people_;
};

