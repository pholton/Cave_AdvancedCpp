// Sets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>

class Person{
private:
	char *name;
	int age;

public:
	// empty constructor is not explicitly necessary
	Person() : name(""), age(0) {};

	Person(char *name, int age) : name(name), age(age) {};

	// must be const
	void Person::printPerson() const {
		std::cout << name << ": " << age << std::flush;
	}
	
	// overload the '<' operator to compare ages and names
	bool operator<(const Person &other) const {
		if (age == other.age) {
			return name < other.name;
		}
		else {
			return age < other.age;
		}
	}
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	// Set can only have one instance of a variable/object
	std::set<int> numbers;

	numbers.insert(15);
	numbers.insert(5);
	numbers.insert(10);
	numbers.insert(20);
	numbers.insert(0);
	numbers.insert(20);  // is ignored since 20 is already in set

	for (std::set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	// Can use x.find('test') to see if a 'test' is in set using an iterator
	std::set<int>::iterator itFind = numbers.find(20);
	if (itFind != numbers.end()) {
		std::cout << "Found: " << *itFind << "\n" << std::endl;
	}

	// x.count('test') will return 1 if 'test' is found, 
	// 0 if 'test' is not found.
	if (numbers.count(30)) {
		std::cout << "Number found.\n" << std::endl;
	}
	else {
		std::cout << "Number not found.\n" << std::endl;
	}

	// Can build a set of objects
	std::set<Person> people;
	people.insert(Person("Steve", 35));
	people.insert(Person("Dave", 50));
	people.insert(Person("Lana", 25));
	people.insert(Person("Zane", 44));
	people.insert(Person("Dave", 25));

	for (std::set<Person>::iterator it = people.begin(); it != people.end(); it++) {
		it->printPerson();
		std::cout << std::endl;
	}

	return 0;
}

