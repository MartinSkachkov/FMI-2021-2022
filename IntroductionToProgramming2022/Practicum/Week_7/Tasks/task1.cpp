#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int a, b;
	do {
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	} while (b < a);

	cout << "funny numbers in the interval [" << a << ',' << b << "]\n";
	for (int i = a; i <= b; i++) {
		bool isFunny = true;
		int currNumber = abs(i);

		while (currNumber != 0) {
			int lastDigit = currNumber % 10 % 2;
			int previousDigit = currNumber / 10 % 10 % 2;

			if (currNumber <= 10) {
				break;
			}

			if (lastDigit == previousDigit) {
				isFunny = false;
				break;
			}
			currNumber /= 10;
		}
		if (isFunny) {
			cout << i << ' ';
		}
	}
	cout << endl;
	
	int sum = 0;
	cout << "funny numbers:\n";
	for (int i = a; i <= b; i++) {
		bool isFunny = true;
		int currNumber = abs(i); // abs doesn't work with size_t

		int digitSum = 0, digitSumCopy;
		while (currNumber != 0) {
			digitSum += currNumber % 10;
			currNumber /= 10;
		}

		digitSumCopy = digitSum;

		while (digitSum != 0) {
			int lastDigit = (digitSum % 10) % 2;
			int previousDigit = (digitSum / 10 % 10) % 2;

			if (digitSum <= 10) {
				break;
			}

			if (lastDigit == previousDigit) {
				isFunny = false;
				break;
			}
			digitSum /= 10;
		}

		if (isFunny) {
			sum += i;
			cout << "sum of digits: " << digitSumCopy << " current number: " << i << endl;
		}
	}
	cout << endl << "SUM: " << sum;

	return 0;
}