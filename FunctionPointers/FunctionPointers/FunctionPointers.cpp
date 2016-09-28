// FunctionPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool match(std::string s);
int countStrings(std::vector<std::string> &texts, bool (*match)(std::string test));

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::string> texts;

	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("four");
	texts.push_back("two");
	texts.push_back("five");
	texts.push_back("six");

	std::cout << match(texts[3]) << std::endl;

	// pass match to the countStrings function
	std::cout << countStrings(texts, match) << std::endl;

	// use count_if from algorithm library
	std::cout << count_if(texts.begin(), texts.end(), match) << std::endl;

	return 0;
}

bool match(std::string s) {
	// return true if the string is three characters in length
	return s.size() == 3;
}

// (*match) passes the function pointer (match) to countStrings 
int countStrings(std::vector<std::string> &texts, bool (*match)(std::string test)) {
	int count = 0;
	for (int i = 0; i < texts.size(); i++) {
		// call match function
		if (match(texts[i])) {
			count++;
		}
	}
	return count;
}