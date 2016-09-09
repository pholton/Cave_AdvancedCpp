// Vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>


int _tmain(int argc, _TCHAR* argv[])
{

	std::vector<double> numbers(0);

	std::cout << "Size: " << numbers.size() << std::endl;

	int capacity = numbers.capacity();
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	for (int i = 0; i < 10000; i++) {
		if (numbers.capacity() != capacity) {
			capacity = numbers.capacity();
			std::cout << "Capacity: " << numbers.capacity() << std::endl;
		}

		numbers.push_back(i);
	}

	numbers.resize(100);
	std::cout << "\nResize vector to 100 elements" << std::endl;
	std::cout << numbers[25] << std::endl;
	std::cout << "Size: " << numbers.size() << std::endl;
	std::cout << "Capacity: " << numbers.capacity() << "\n" << std::endl;

	numbers.clear();
	std::cout << "Clear vector" << std::endl;
	std::cout << "Size: " << numbers.size() << std::endl;
	std::cout << "Capacity: " << numbers.capacity() << "\n" << std::endl;

	numbers.reserve(100000);
	std::cout << "Reserve memory for 100000 elements" << std::endl;
	std::cout << "Size: " << numbers.size() << std::endl;
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	return 0;
}

