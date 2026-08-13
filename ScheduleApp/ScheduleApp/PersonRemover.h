#pragma once

#include <vector>

#include "Person.h"


class PersonRemover
{
private:
	int current_page_;
	const int kMaxPerPage = 7;
	std::vector<Person>* people_;

	void showPeople();
	void dispPersonDetail(int id);
	bool removePerson(int id);
public:
	PersonRemover(std::vector<Person>* people);

	void run();
};

