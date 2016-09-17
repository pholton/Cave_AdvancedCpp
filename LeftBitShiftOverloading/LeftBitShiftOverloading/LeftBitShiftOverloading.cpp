// LeftBitShiftOverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Test.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Test test1(5, "Steve");
	Test test2;

	test2 = test1;
	std::cout << test2 << "\n" << test1 << std::endl;

	return 0;
}

