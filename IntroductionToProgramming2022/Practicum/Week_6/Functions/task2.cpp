#include <iostream>
using namespace std;

unsigned int isEven(int a, int b) {
	unsigned int counter = 0;
	cout << "Even numbers: ";
	for (size_t i = a; i <= b; i++) {
		if (i % 2 == 0) {
			counter++;
			cout << i << ' ';
		}
	}
	cout << endl;
	return counter;
}

int main() {
	int a, b;
	do {
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	} while (a > b);

	cout << "Count of even numbers is: " << isEven(a, b);
	return 0;
}
