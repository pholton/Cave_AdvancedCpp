// StackAndQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

class Test {
private:
	std::string name;

public:
	Test(std::string name) : name(name) {

	}

	~Test() {
		//std::cout << "Object destroyed." << std::endl;
	}

	void print() {
		std::cout << name << std::endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{

	//// Stacks are LIFO (last in, first out) ////
	std::stack<Test> testStack;

	// Push items on to the top of the stack
	testStack.push(Test("Tim"));
	testStack.push(Test("Sue"));
	testStack.push(Test("John"));
	testStack.push(Test("Dave"));

	// create a reference to the object on top of the stack
	// this way we don't create a copy of the object (more efficient).
	// Here we only print, so the object is still at the top of the stack.
	Test &test1 = testStack.top();
	std::cout << "Top of the stack: " << std::flush;
	test1.print();
	std::cout << std::endl;
	
	/*******************************************************************
	If you create a reference to an object in the stack,
	you must use the reference variable before you pop
	the object off of the stack, because the object
	is destroyed after it is popped.

	//// Bad Code ////
	Test &testBad = testStack.top();
	testStack.pop();
	testBad.print();  // Reference refers to a destroyed object
	*******************************************************************/

	while (testStack.size() > 0) {
		testStack.top().print();
		testStack.pop();
	}
	std::cout << "\n" << std::endl;


	//// Queue is FIFO (first in, first out) ////
	std::queue<Test> testQueue;

	testQueue.push(Test("Jim"));
	testQueue.push(Test("Steve"));
	testQueue.push(Test("Eric"));
	testQueue.push(Test("John"));

	Test &test2 = testQueue.back();
	std::cout << "Back of the queue: " << std::flush;
	test2.print();
	std::cout << std::endl;


	// Can also loop through objects with for loop
	/*
	for (; testQueue.size() > 0; testQueue.pop()) {
		testQueue.front().print();
	}
	*/
	
	while (testQueue.size() > 0) {
		Test &testFront = testQueue.front();
		testFront.print();
		testQueue.pop();
	}
	
	return 0;
}

