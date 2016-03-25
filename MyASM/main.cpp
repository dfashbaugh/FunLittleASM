#include <iostream>
#include <vector>
#include "Commands.h"
#include "commandTests.h"

#define RUNTESTS

using namespace std;

void printRegisters(std::vector <int> &registers)
{
	cout << endl << "Print Register List" << endl;

	int counter = 0;

	for(auto &number : registers)
	{
		cout << counter << " " << number << endl;
		counter++;
	}

	cout << endl << "End Print Register List" << endl;
}

void executeProgram(std::vector <command*> commandVector)
{
	int programCounter = 0;
	bool done = false;
	std::vector <int> registers;

	while(!done)
	{
		commandVector[programCounter]->execute(registers, programCounter);

		if(programCounter >= commandVector.size()) done = true;
	}

	printRegisters(registers);
}

int main(void)
{
	cout << "Begin!" << endl;

#ifdef RUNTESTS
	if(!runTests()) return 1; // Return failure
#endif

	// Write the program
	std::vector <command*> commandVector;
	commandVector.push_back(new set(0, 20));
	commandVector.push_back(new set(1, 4));
	commandVector.push_back(new add(0, 0, 0));
	commandVector.push_back(new set(5, 10));
	commandVector.push_back(new add(3, 1, 5));

	// Execute the program
	executeProgram(commandVector);

	cout << "End!" << endl;
	return 0;
}