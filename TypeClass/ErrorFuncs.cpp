#include <iostream>
#include "ErrorFuncs.h"

using namespace std;

void err::incompatibleTypes(string op, string opType)
{
	cout << "The operation '" << op << "' cannot happen between incompatible types! Right operand should also be of type '" << opType << "'" << endl
		<< "Terminating..." << endl;
	_Exit(1);
}

void err::noSuchOp(string op, string opType)
{
	cout << "The operation " << "'" << op << "'" << " does not exist for type '" << opType << "'!" << endl
		<< "Terminating..." << endl;
	_Exit(1);
}