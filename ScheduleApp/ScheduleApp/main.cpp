#include <iostream>

#include "Event.h"
#include "InputHandler.h"
#include "Person.h"

int main() {
	Person p1("Alice");
	Event e1;

	std::cout << e1.hasEmpty() << std::endl;
	return 0;
}