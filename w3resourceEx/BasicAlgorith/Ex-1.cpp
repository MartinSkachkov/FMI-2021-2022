#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num1, num2, sum;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;

	cout<< (num1 == num2 ? (sum = 3 * (num1 + num2)) : (num1 + num2));
}
