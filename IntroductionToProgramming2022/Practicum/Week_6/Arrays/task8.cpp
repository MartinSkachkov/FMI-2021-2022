#include <iostream>
#define MAX_SIZE 100
using namespace std;

int main() {
	int data[MAX_SIZE] = {0};
	int lowerBound, upperBound, n;
	cout << "n: ";
	cin >> n;

	do {
		for (size_t i = 0; i < n; i++) {
			cin >> data[i];
		}
		if (data[0] > data[n - 1]) {
			cout << "Invalid input! Re-enter it again";
		}
	} while (data[0] > data[n - 1]);


	lowerBound = data[0];
	upperBound = data[n - 1];

	bool allContained = false;
	for (size_t i = lowerBound; i <= upperBound; i++) {
		bool currentIsContained = false;
		for (size_t j = 0; j < n; j++) {
			if (data[j] == i) {
				currentIsContained = true;
				break;
			}
			else {
				currentIsContained = false;
			}
		}
		if (!currentIsContained) {
			allContained = false;
			break;
		}
		else {
			allContained = true;
		}
	}

	cout << "All contained? " << boolalpha << allContained;

	return 0;
}
