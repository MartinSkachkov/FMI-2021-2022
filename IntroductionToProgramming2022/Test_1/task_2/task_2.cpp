#include <iostream>
#include<cstdlib>
using namespace std;

int main() {
	int a, b;
	do {
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	} while (a > b);

	cout << "All neighbour numbers:\n";
	int min = INT_MAX, max = INT_MIN, currentNum;
	bool isNeighbour = true;
	for (int i = a; i <= b; i++) {
		isNeighbour = true;
		currentNum = abs(i);
		while (currentNum != 0) {
			int lastDigit = currentNum % 10;
			int previousDigit = currentNum / 10 % 10;

			if (lastDigit == previousDigit) {
				isNeighbour = false;
				break;
			}
			currentNum /= 10;
		}
		if (isNeighbour) {
			cout << i << ' ';
			if (i > max) {
				max = i;
			}
			if (i < min) {
				min = i;
			}
		}
	}

	cout << endl << "Min: " << min << endl << "Max: " << max << endl;
	cout << "Result: " << max - min;
	return 0;
}
