// TwoDimensionalVectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

int _tmain(int argc, _TCHAR* argv[])
{
	// Create a 2-dimensional vector that is 3 rows x 4 columns
	// of ints, all the elements are initialized to 5
	std::vector< std::vector<int> > grid(3, std::vector<int>(4, 5));

	std::cout << grid.size() << std::endl;
	std::cout << grid[0].size() << std::endl;

	for (int row = 0; row < (int)grid.size(); row++) {
		for (int col = 0; col < (int)grid[row].size(); col++) {
			std::cout << grid[row][col] << std::flush;
		}
		std::cout << std::endl;
	}

	return 0;
}

