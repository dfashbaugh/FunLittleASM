#include "Commands.h"
#include <iostream>
using namespace std;

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