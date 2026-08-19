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
	int getId() const;
	void setId(int id);
	std::string getName() const;
	void setName(std::string name);
	const std::vector<int>& getParticipants() const ;
	std::string getParticipantsString() const ;
	void setParticipantFromString(std::string participants);
	void addParticipant(int person_id);
	void removeParticipant(int person_id);
	std::string getStartDateTimeString() const;
	void setStartDateTime(std::string start_datetime);
	std::string getEndDateTimeString() const;
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