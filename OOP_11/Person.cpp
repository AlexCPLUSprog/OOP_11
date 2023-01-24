#include "Person.h"

Person::Person(const std::string& name) : _name(name) {}

void Person::fight() {
	std::cout << "Person is fighting" << '\n';
}

const std::string& Person::getName() {
	return _name;
}