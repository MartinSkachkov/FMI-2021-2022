#include <iostream>
using namespace std;

int main()
{//swap two numbers
	int a, b, c = 0; 
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	c = a;
	a = b;
	b = c;
	cout << "a: " << a << ", " << "b: " << b;
}
