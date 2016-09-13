// Multimap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{

	// Multimap allows us to create maps with multiple uses of the same key.
	// Can typically be written with a standard map using a vector, list, or 
	// custom object instead of a multimap.
	std::multimap<int, std::string> lookup;

	// Have to use insert to add values to a multimap, cannot use the overloaded 
	// array syntax that can be used with maps ([]).
	lookup.insert(std::make_pair(30, "Mike"));
	lookup.insert(std::make_pair(10, "Vicky"));
	lookup.insert(std::make_pair(30, "Frank"));
	lookup.insert(std::make_pair(25, "John"));

	// Loop through each key/value pair in the multimap and print the key and value
	for (std::multimap<int, std::string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << std::endl;

	// Find will allow us to find a specific key, however if we use the for loop with find,
	// we will find the key, and then return all of the keys that occur after the found key.
	// In this case we get 25, 30, and 30.
	for (std::multimap<int, std::string>::iterator it = lookup.find(25); it != lookup.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << std::endl;

	// We can use a pair of iterators to store the range that holds a specific lookup value using x.equal_range('key to find')
	// This is the C++98 method for generating the pair of iterators
	std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> its = lookup.equal_range(30);
	// The loop starts at the first iterator created above, and returns values as long as the loop iterator
	// does not hit the second iterator created above, so it only will return the key/values pairs
	// that were searched for.
	for (std::multimap<int, std::string>::iterator it = its.first; it != its.second; it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << std::endl;

	// C++11 version of creating the pair of iterators. Auto gets the correct type for the requested operation.
	// In this case, a pair of iterators for the .equal_range() method to return to.
	auto its2 = lookup.equal_range(30);
	for (std::multimap<int, std::string>::iterator it = its2.first; it != its2.second; it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}

	return 0;
}

