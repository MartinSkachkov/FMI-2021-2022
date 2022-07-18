#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int a, b;
	const unsigned int r = 5;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;

	cout << boolalpha << ((a % 2 == 1) || (b % 2 == 1)) << endl;
	cout << boolalpha << (a * a + (b - 1) * (b - 1) <= 25) << endl; //C(0,1)
}