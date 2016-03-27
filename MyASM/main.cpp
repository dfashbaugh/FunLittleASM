#include <iostream>
#include <vector>
#include "Commands.h"
#include "commandTests.h"

#define RUNTESTS

using namespace std;

int main(void)
{
	cout << "Begin!" << endl;

#ifdef RUNTESTS
	if(!runTests()) return 1; // Return failure
#endif

	// Write the program
	std::vector <command*> commandVector;
	//commandVector.push_back(new set(0, 20));
	//commandVector.push_back(new set(1, 4));
	//commandVector.push_back(new add(0, 0, 0));
	//commandVector.push_back(new set(5, 10));
	//commandVector.push_back(new add(3, 1, 5));
	commandVector.push_back(new set(0, 0));
	commandVector.push_back(new set(1, 1));
	commandVector.push_back(new set(2, 20));
	commandVector.push_back(new add(0, 1, 0));
	commandVector.push_back(new branchGreaterThan(2, 0, 3));

	// Execute the program
	executeProgram(commandVector);

	cout << "End!" << endl;
	return 0;
}