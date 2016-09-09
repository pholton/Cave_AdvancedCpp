// WritingToBinary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

// pack(push, 1) will remove any padding from the struct
// so it can easily be written to a file
#pragma pack(push, 1)
struct Person {
	char name[60];
	int age;
	double height;
};
#pragma pack(pop)

int _tmain(int argc, _TCHAR* argv[])
{
	Person someone = { "Frodo", 220, 0.8 };

	char *filename = "test.bin";


	//// Write struct to binary file
	std::ofstream outputFile;
	outputFile.open(filename, std::ios::binary);

	/* Can also open file with fstream as follows
	std::fstream outputFile;
	outputFile.open(filename, std::ios::binary | std::ios::open);
	*/

	if (outputFile.is_open()) {
		// reinterpret_cast is a better way to cast a variable than traditional casting
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		outputFile.close();
	}
	else {
		std::cout << "Could not open file: " << filename << std::endl;
	}


	//// Read struct from binary file
	Person someoneElse = {};

	std::ifstream inputFile;
	inputFile.open(filename, std::ios::binary);

	if (inputFile.is_open()) {
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

		inputFile.close();
	}
	else {
		std::cout << "Could not read file: " << filename << std::endl;
	}

	std::cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << std::endl;

	return 0;
}

