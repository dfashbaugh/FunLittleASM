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

bool testAddCommand()
{
	SETUP_FOR_EXECUTION

	registers.push_back(10);
	registers.push_back(5);

	command* theCommand = new add(10, 1, 0);
	theCommand->execute(registers, programCounter);

	if(registers[10] != 15)
	{
		cout <<"Test: Add Test Failure" << endl;
		return false;
	}

	return true;
}

bool testSetAndAdd()
{
	SETUP_FOR_EXECUTION

	std::vector <command*> commands;
	commands.push_back(new set(1,10));
	commands.push_back(new set(0, 5));
	commands.push_back(new add(2, 1, 0));

	commands[0]->execute(registers, programCounter);
	commands[1]->execute(registers, programCounter);
	commands[2]->execute(registers, programCounter);

	if(registers[2] != 15)
	{
		cout << "Test: Set and Add Test Failure" << endl;
		return false;
	}

	return true;
}

bool runTests()
{
	if(!testSetCommand()) return false;
	if(!testAddCommand()) return false;
	if(!testSetAndAdd()) return false;

	cout << "Test: All Tests Passed!" << endl;
	return true;
}