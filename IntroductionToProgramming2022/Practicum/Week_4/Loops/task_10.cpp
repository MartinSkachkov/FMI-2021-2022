#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nCopy = abs(n);
	int counter = 0;

	while (nCopy != 0) { //find the number of digits
		nCopy /= 10;
		counter++;
	}
	nCopy = abs(n);
	unsigned int sum = 0, rem;

	for (size_t i = 0; i < counter; i++) { //calculate the sum of the digits
		rem = nCopy % 10;
		sum += pow(rem, counter);
		nCopy /= 10;
	}

	if (n == sum) {
		cout << "narcissistic number";
	}
	else {
		cout << "not narcissistic number";
	}

	return 0;
}