#pragma once

#include <chrono>
#include <string>
#include <vector>


class Event
{
public:
	Event();
	int removeThisFromParticipants();

	bool hasEmpty();
	int getId();
	void setId(int id);
	std::string getName();
	void setName(std::string name);
	std::string getParticipantsString();
	void setParticipantFromString(std::string participants);
	void addParticipant(int person_id);
	void removeParticipant(int person_id);
	std::string getStartDateTimeString();
	void setStartDateTime(std::string start_datetime);
	std::string getEndDateTimeString();
	void setEndDateTime(std::string end_datetime);
	static void updateMaxId(int max_id);

	bool hasPerson(int person_id);

private:
	static int max_id;
	int id_;
	std::string name_;
	std::vector<int> participants_;
	std::chrono::sys_seconds start_datetime_;
	std::chrono::sys_seconds end_datetime_;
};