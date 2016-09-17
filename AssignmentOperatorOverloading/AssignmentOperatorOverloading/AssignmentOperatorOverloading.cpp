// AssignmentOperatorOverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Test{
private:
	int id;
	std::string name;

public:

	Test() : id(0), name("") {}

	Test(int id, std::string name) : id(id), name(name) {

	}

	Test(const Test &other) {
		std::cout << "Copy constructor running." << std::endl;
		/*
		id = other.id + 1;
		name = other.name;
		*/

		// Invokes the overloaded assignment operator
		*this = other;
	}

	~Test() {}

	void print() {
		std::cout << id << ": " << name << std::endl;
	}

	const Test &operator=(const Test &other) {
		std::cout << "Assignment operator running." << std::endl;
		id = other.id + 1;
		name = other.name;
		return *this;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Test test1(10, "Mike");
	std::cout << "Test1: " << std::flush;
	test1.print();
	std::cout << "Test1 Address: " << &test1 << "\n" << std::endl;

	Test test2 = test1;
	std::cout << "Test2: " << std::flush;
	test2.print();
	std::cout << "Test2 Address: " << &test2 << "\n" << std::endl;

	Test test3;
	test3 = test2 = test1;
	std::cout << "Test3: " << std::flush;
	test3.print();
	std::cout << "Test3 Address: " << &test3 << "\n" << std::endl;

	Test test4(15, "Tom");
	test4.operator=(test3);
	std::cout << "Test4: " << std::flush;
	test4.print();
	std::cout << "Test4 Address: " << &test4 << "\n" << std::endl;


	return 0;
}

