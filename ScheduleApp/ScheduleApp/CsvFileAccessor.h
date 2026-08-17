#pragma once

#include <string>
#include <vector>

#include "Event.h"
#include "Person.h"


class CsvFileAccessor
{
public:
	CsvFileAccessor(
		std::vector<Person>* people,
		std::vector<Event>* events);

	bool writeFiles();
	bool readFiles();

private:
	bool writePerson();
	bool writeEvents();
	bool readPerson();
	bool readEvents();

	std::string kPersonFilePath;
	std::string kEventFilePath;
	std::vector<Person>* people_;
	std::vector<Event>* events_;
};