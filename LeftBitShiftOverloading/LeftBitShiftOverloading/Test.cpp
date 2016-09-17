#include "stdafx.h"
#include "Test.h"
#include <iostream>

// Overload the assignment operator
const Test &Test::operator=(const Test &other) {
	id = other.id;
	name = other.name;
	return *this;
}

int Test::getId() {
	return id;
}

char *Test::getName() {
	return name;
}

// Overload the left bitshift operator for ostream
// returns an ostream object
std::ostream &operator<<(std::ostream &out, Test &test) {
	out << test.getId() << ": " << test.getName();
	return out;
}