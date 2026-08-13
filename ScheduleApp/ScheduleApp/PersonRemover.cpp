#include "PersonRemover.h"

#include <vector>

#include "Person.h"


PersonRemover::PersonRemover(std::vector<Person>* people) 
	: people_(people) , current_page_(1) {}

void PersonRemover::run() {

}

void PersonRemover::showPeople() {

}

void PersonRemover::dispPersonDetail(int id) {

}

bool PersonRemover::removePerson(int id) {
	return false;
}