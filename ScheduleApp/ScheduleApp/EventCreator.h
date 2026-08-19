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
	enum class Mode {
		kChoiceMethod = 0,
		kEditEvent,
		kConfirmEvent,
		kEditCondition,
		kConfirmCondition,
		kTerminate,
	};

	int choiceMethod();

	bool editEvent(Event& event);
	bool confirmEvent(const Event& event);
	bool addEvent(const Event& event);

	bool editEventCondition(EventCondition& condition);
	bool proposeEvent(const EventCondition& condition, Event& event);
	bool confirmCondition(const EventCondition& condition);

	std::vector<int> pickParticipants();
	std::vector<Event> collectEvents(std::vector<int> target_people);

	std::vector<Person>* people_;
	std::vector<Event>* events_;
	Mode mode_;
};