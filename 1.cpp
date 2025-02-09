#include <iostream>
#include <string>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::string;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int& f()
{
	static int x = 10;
	return x;
}

int foo() {
	return 1;
}

int foo(int a, int b)
{
	return 2;
}

int foo(double a, double b)
{
	return 3;
}

void zoo();
void zoo(int a) {}
void zoo(int a, int b) {}
void zoo(int b, int a = 5, int c = 10) {}

int main()
{
	cout << "Hello, world!" << endl;
	//int n = 0;
	//double b = 0;
	//cin >> n >> b;
	//cout << n << " " << b << "\n";*/
	//string s;
	////cin >> s;
	////std::getline(cin, s);
	////cout << s.c_str() << endl;
	////cout << s << endl;
	int a = 5, b = 7;
	///*cout << a << " " << b << endl;
	swap(a, b);
	//cout << a << " " << b << endl;*/
	//f() = 15;
	//cout << a<<" "<<f()<<" "<<b << endl;
	//int& ref = a;
	//ref = b;
	//cout << a << " " << b << endl;
	//const int& ref2 = 5;
	/*double c = 2.0;
	cout << foo(c, 3.0) << endl;*/
	

	return 0;
}