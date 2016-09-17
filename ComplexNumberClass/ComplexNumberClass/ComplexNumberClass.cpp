// ComplexNumberClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "complex.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{

	cop::Complex c1(2, 3);
	cop::Complex c2 = c1;
	cop::Complex c3;

	c3 = c2;

	std::cout << c1 << " " << c3 << std::endl;

	std::cout << c1 + c2 << std::endl;

	cop::Complex c4 = c3 + 5;
	std::cout << c4 << std::endl;
	c4 = 3 + c4;
	std::cout << c4 << std::endl;

	if (c1 == c4) {
		std::cout << "Equal" << std::endl;
	}
	else {
		std::cout << "Not equal" << std::endl;
	}

	if (c1 != c4) {
		std::cout << "Not Equal" << std::endl;
	}
	else {
		std::cout << "Equal" << std::endl;
	}

	return 0;
}

