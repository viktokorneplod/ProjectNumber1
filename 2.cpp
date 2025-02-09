#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void swa(int& a, int& b)
{
	cout << "Hello, world!" << endl;
	int temp = a;
	a = b;
	b = temp;
}

