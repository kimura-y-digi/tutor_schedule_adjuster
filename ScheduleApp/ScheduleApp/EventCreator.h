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
		kConfirmRegistEvent,
		kEditCondition,
		kConfirmProposedEvent,
		kTerminate,
	};

	int choiceMethod();

	bool editEvent(Event& event);
	bool confirmRegistEvent(const Event& event);
	bool addEvent(const Event& event);

	bool editEventCondition(EventCondition& condition);
	bool proposeEvent(const EventCondition& condition, Event& event);
	bool confirmProposedEvent(const Event& event);

	std::vector<int> pickParticipants();
	std::vector<Event> collectEvents(std::vector<int> target_people);

	std::vector<Person>* people_;
	std::vector<Event>* events_;
	Mode mode_;
};