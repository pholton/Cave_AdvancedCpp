// MapsCustomObjectsAsKeys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>


class Person {
private:
	std::string name;
	int age;

public:

	Person() : name(""), age(0) {

	}

	Person(const Person &other) {
		std::cout << "Copy Constructor Called!" << std::endl;
		name = other.name;
		age = other.age;
	}

	Person(std::string name, int age) :
		name(name), age(age) {

	}

	// Needs to be const to work with the iterator
	// Should be const anyway since the print has no need to change the object
	void print() const {
		std::cout << name << ": " << age << std::flush;
	}


	//// Operator Overloading ////
	/*
	* Changes the behavior of the '<' symbol for this class (in this case 
	* there is no default behavior)
	* This is required for the key in the map, because the keys need to be 
	* compared in order to be sorted
	* The method needs to be const, and the argument needs to be const
	* because the operator should not have the ability to adjust the object
	* it is called from or the object it is comparing to.
	* The other object is passed by reference so we don't create a copy
	* of the object just for the comparison. Since it is const, there is
	* no risk in using the reference to the object.
	*/
	bool operator<(const Person &other) const {
		// if the names are the same, then compare by age
		if (name == other.name) {
			return age < other.age;
		}
		else {
			// can use the string compare '<'
			return name < other.name;
		}
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	std::map<Person, int> people;

	people[Person("Steve", 30)] = 30;
	people[Person("Sue", 25)] = 55;
	people[Person("Sue", 15)] = 40;
	people[Person("John", 40)] = 40;

	for (std::map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
		std::cout << it->second << ". " << std::flush;
		it->first.print();
		std::cout << std::endl;
	}

	return 0;
}