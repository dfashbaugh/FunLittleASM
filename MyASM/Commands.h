#include <vector>

struct command
{
	int TestVal;

	virtual void execute(std::vector <int> &registers, int &programCounter) = 0;
};

// Sets a value a setAddr to setValue
struct set : command
{
	int setAddr;
	int setValue;

	set(int setAddress, int setter)
	{
		setAddr = setAddress;
		setValue = setter;
	}

	virtual void execute(std::vector<int> &registers, int &programCounter);
};

// Adds the values at 2 given addresses and places that value into the sumaddress
struct add : command
{
	int sumAddr;
	int opAddr1;
	int opAddr2;

	add(int sumAddress, int opAddress1, int opAddress2)
	{
		sumAddr = sumAddress;
		opAddr1 = opAddress1;
		opAddr2 = opAddress2;
	}

	virtual void execute(std::vector <int> &registers, int &programCounter);
};

struct subtract : command
{
	int diffAddr;
	int opAddr1;
	int opAddr2;

	subtract(int diffAddress, int opAddress1, int opAddress2)
	{
		diffAddr = diffAddress;
		opAddr1 = opAddress1;
		opAddr2 = opAddress2;
	}

	virtual void execute(std::vector <int> &registers, int &programCounter);
};

struct multiply : command
{
	int prodAddr;
	int opAddr1;
	int opAddr2;

	multiply(int productAddress, int opAddress1, int opAddress2)
	{
		prodAddr = productAddress;
		opAddr1 = opAddress1;
		opAddr2 = opAddress2;
	}

	virtual void execute(std::vector <int> &registers, int &programCounter);
};