#ifndef _TEST_H_
#define _TEST_H_

#include <iostream>

class Test{
private:
	int id;
	char *name;

public:

	Test() : id(0), name("") {};

	Test(int id, char *name) : id(id), name(name) {};

	Test(const Test &other) { *this = other; };

	~Test() {};

	const Test &operator=(const Test &other);

	int getId();

	char *getName();
};

// Does not need to be a friend function to Test
// because we are using getters, and not accessing
// the instance variables directly. Because of this we
// also do not need to prototype the function inside
// of the test class.
std::ostream &operator<<(std::ostream &out, Test &test);

#endif