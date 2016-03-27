#include "Commands.h"
#include <iostream>
using namespace std;

// Print the whole register list
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

// Execute the program defined by the commandVector
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

// Set the register buffer to the correct size based on the maximum address
void setRegisterSize(std::vector <int> &registers, int maxAddr)
{
	while(registers.size() <= maxAddr)
	{
		registers.push_back(0);
	}
}

void set::execute(std::vector <int> &registers, int &programCounter)
{
	setRegisterSize(registers, setAddr);

	registers[setAddr] = setValue;

	programCounter++;
}

void add::execute(std::vector <int> &registers, int &programCounter)
{
	setRegisterSize(registers, std::max(std::max(sumAddr, opAddr1), opAddr2));

	registers[sumAddr] = registers[opAddr1] + registers[opAddr2];

	programCounter++;
}

void subtract::execute(std::vector <int> &registers, int &programCounter)
{
	setRegisterSize(registers, std::max(std::max(diffAddr, opAddr1), opAddr2));

	registers[diffAddr] = registers[opAddr1] - registers[opAddr2];

	programCounter++;
}

void multiply::execute(std::vector <int> &registers, int &programCounter)
{
	setRegisterSize(registers, std::max(std::max(prodAddr, opAddr1), opAddr2));

	registers[prodAddr] = registers[opAddr1] * registers[opAddr2];

	programCounter++;
}

void branchEqualTo::execute(std::vector <int> &registers, int &programCounter)
{
	setRegisterSize(registers, std::max(opAddr2, opAddr1));

	if(registers[opAddr1] == registers[opAddr2])
	{
		programCounter = brAddr;
	} 
	else 
	{
		programCounter++;
	}
}

void branchNotEqualTo::execute(std::vector <int> &registers, int &programCounter)
{
	setRegisterSize(registers, std::max(opAddr2, opAddr1));

	if(registers[opAddr1] != registers[opAddr2])
	{
		programCounter = brAddr;
	} 
	else 
	{
		programCounter++;
	}
}

void branchGreaterThan::execute(std::vector <int> &registers, int &programCounter)
{
	setRegisterSize(registers, std::max(opAddr2, opAddr1));

	if(registers[opAddr1] > registers[opAddr2])
	{
		programCounter = brAddr;
	} 
	else 
	{
		programCounter++;
	}
}