#pragma once

#include <vector>

#include "Person.h"


class PersonCreator
{
public:
	PersonCreator(std::vector<Person>* people);

	void run();

private:
	std::vector<Person>* people_;
};