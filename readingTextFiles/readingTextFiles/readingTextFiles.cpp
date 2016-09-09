// readingTextFiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{

	std::string inFileName = "test.txt";
	std::fstream inFile;

	inFile.open(inFileName, std::ios::in);

	if (inFile.is_open()) {
		std::string line;

		while (!inFile.eof()) {
			getline(inFile, line);
			std::cout << line << std::endl;
		}

		inFile.close();
	}
	else {
		std::cout << "Cannot open file: " << inFileName << std::endl;
	}

	return 0;
}

