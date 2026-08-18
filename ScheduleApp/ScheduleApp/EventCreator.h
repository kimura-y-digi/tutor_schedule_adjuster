#pragma once

#include <vector>

#include "Event.h"
#include "EventCondition.h"
#include "Person.h"


class EventCreator
{
public:
	EventCreator(std::vector<Person>* people, std::vector<Event>* events);

	void run();

private:
	int choiceMethod();

	int editEvent(Event proposed = Event());
	std::vector<int> pickParticipants();
	void addEvent(const Event& event);

	Event editEventCondition();
	std::vector<Event> collectEvents(std::vector<int> target_people);
	bool proposeEvent(
		EventCondition cd,
		const std::vector<Event>& events,
		Event& out_event
	);

	std::vector<Person>* people_;
	std::vector<Event>* events_;
};