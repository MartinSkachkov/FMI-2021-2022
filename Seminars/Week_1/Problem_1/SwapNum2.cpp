#include <iostream>
using namespace std;

int main()
{//swap two numbers
	int a, b; 
	cout << "Enter a: ";
	cin >> a; //2
	cout << "Enter b: ";
	cin >> b; //3
	a = a + b; //a = 5
	b = a - b; //b = 2
	a = a - b; //a = 5 - 2 = 3
	cout << "a: " << a << ", " << "b: " << b;
}
