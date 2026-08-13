#pragma once

#include <vector>

#include "Person.h"


class PersonCreator
{
private:
	std::vector<Person>* people_;
public:
	PersonCreator(std::vector<Person>* people);
	void run();
};