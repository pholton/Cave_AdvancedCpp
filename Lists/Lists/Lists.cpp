// Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

int _tmain(int argc, _TCHAR* argv[])
{
	// Initialize a list of integers
	std::list<int> numbers;

	// Add values to the list (beginning and end elements)
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	// Initialize iterator to move through the list
	// cannot use indexing since the list uses pointers
	// to move between different elements
	std::list<int>::iterator it = numbers.begin();
	// Insert 100 1 element from the beginning
	numbers.insert(++it, 100);
	std::cout << "Element: " << *it << std::endl;

	// Reset iterator
	it = numbers.begin();
	it++;
	// Erase element 1 from the beginning
	it = numbers.erase(it);
	std::cout << "Element: " << *it << std::endl;

	// Initialize new iterator, could just reset it = numbers.begin()
	std::list<int>::iterator iter = numbers.begin();
	while (iter != numbers.end()) {
		if (*iter == 2) {
			numbers.insert(iter, 1234);
		}
		if (*iter == 1) {
			// Erase increments the iterator to the next element
			// so no need to increment (iter++)
			iter = numbers.erase(iter);
		}
		else {
			// If erase is not called, then increment the iterator
			iter++;
		}
	}

	// Loop through each element in the list and print the element
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << std::endl;
	}

	return 0;
}

