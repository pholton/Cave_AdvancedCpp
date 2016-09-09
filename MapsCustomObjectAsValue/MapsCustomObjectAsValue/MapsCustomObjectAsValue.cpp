// MapsCustomObjectAsValue.cpp : Defines the entry point for the console application.
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

	void print() {
		std::cout << name << ": " << age << std::endl;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	std::map<int, Person> people;

	people[0] = Person("Steve", 35);
	people[20] = Person("Tom", 15);
	people[10] = Person("Sue", 22);

	people.insert(std::make_pair(15, Person("Jimbo", 40)));


	for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
		std::cout << it->first << ". " << std::flush;
		it->second.print();
	}

	return 0;
}

