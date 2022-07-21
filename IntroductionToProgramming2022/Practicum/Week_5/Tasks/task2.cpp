#include <iostream>
using namespace std;

bool devisibleByThree(int num) {
	int sum = 0, rem;
	while (num != 0) {
		rem = num % 10;
		sum += rem;
		num /= 10;
	}
	return sum % 3 == 0;
}

int main() {
	const int MAX_SIZE = 1024;
	int arr[MAX_SIZE];

	unsigned int size;
	cout << "Size: ";
	do {
	cin >> size;
	} while (size > 1024);

	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int counter = 0;
	for (size_t i = 0; i < size; i++) {
		if (devisibleByThree(arr[i])) {
			counter++;
			cout << arr[i] << ' ';
		}
	}

	cout << endl;
	cout << "Counter: " << counter << endl;
	return 0;
}