// SortingVectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Test{
private:
	char *name;
	int id;

public:

	Test(int id, char *name) : id(id), name(name) {

	}

	void print() {
		std::cout << id << ": " << name << std::endl;
	}

	// friend functions have access to private instance variables
	// even though they are not a method of the class
	friend bool comp(const Test &a, const Test &b);
};

// Sort objects by id
bool comp(const Test &a, const Test &b) {
	return a.id < b.id;
}


int _tmain(int argc, _TCHAR* argv[])
{

	std::vector<Test> tests;

	tests.push_back(Test(10, "Steve"));
	tests.push_back(Test(5, "John"));
	tests.push_back(Test(20, "Adam"));
	tests.push_back(Test(1, "Tim"));

	// will sort the whole vector (begin() -> end()) using the comp
	// function defined above
	std::sort(tests.begin(), tests.end(), comp);
	
	// print the sorted elements in the vector
	for (int i = 0; i < tests.size(); i++) {
		tests[i].print();
	}

	return 0;
}

