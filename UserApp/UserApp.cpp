#include <iostream>
#include "Dictionary.h"

using namespace std;

int main()
{
	/*Dictionary dict(3, (string)"hello");
	cout << dict << endl;

	dict[4] = (double)5.2345;
	cout << dict << endl;

	dict[(string)"hi"] = (double)2.3;
	cout << dict << endl;

	dict[1.34] = (string)"yes";
	cout << dict << endl;

	dict[4] = (string)"no";
	cout << dict << endl;

	dict[4] = (double)1.76;
	cout << dict << endl;

	cout << dict[3] + dict[1.34] << endl;

	dict[4] = dict[3] - dict[1.34];
	cout << dict << endl;*/

	Dictionary dict1(1, (string)"hi");
	cout << dict1 << endl;

	dict1.insert(2, (string)"hello");
	dict1.insert(3, 4.5678);
	cout << dict1 << endl;

	Dictionary dict2(4, (string)"hi");
	dict2.insert(5, (string)"hello");
	dict2.insert(6, 4.5678);

	cout << dict1 + dict2 << endl;
}