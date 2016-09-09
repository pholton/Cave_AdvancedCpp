// Maps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>


int _tmain(int argc, _TCHAR* argv[])
{
	std::map<char *, int> ages;

	ages["Mike"] = 40;
	ages["Tim"] = 25;
	ages["Tina"] = 30;

	ages.insert(std::make_pair((char *)"Steve", 55));

	if (ages.find("Vicky") != ages.end()) {
		std::cout << "Found Vicky." << std::endl;
	} 
	else {
		std::cout << "Key not found." << std::endl;
	}

	for (std::map<char *, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		std::pair<char *, int> age = *it;

		std::cout << age.first << ", " << age.second << std::endl;
	}


	for (std::map<char *, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		std::cout << it->first << ", " << it->second << std::endl;
	}

	return 0;
}

