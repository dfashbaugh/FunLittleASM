#include "commandTests.h"
#include "Commands.h"
#include <vector>
#include <iostream>

using namespace std;

#define SETUP_FOR_EXECUTION int programCounter = 0; std::vector <int> registers;

bool testSetCommand()
{
	SETUP_FOR_EXECUTION

	command* theCommand = new set(1, 10);
	theCommand->execute(registers, programCounter);

	if(registers[1] != 10)
	{
		cout << "Test: Set Test Failure" << endl;
		return false;
	}

	return true;
}

bool runTests()
{
	if(!testSetCommand()) return false;

	cout << "Test: All Tests Passed!" << endl;
	return true;
}