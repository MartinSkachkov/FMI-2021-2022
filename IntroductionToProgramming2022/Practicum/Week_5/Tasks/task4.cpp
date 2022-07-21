#include <iostream>
using namespace std;

int main() {
	const int MAX_SIZE = 1024;
	int arr[MAX_SIZE];

	unsigned int size;
	do {
		cin >> size;
	} while (size > 1000);

	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "Original arr:\n";
	for (size_t i = 0; i < size; i++) {
		cout << arr[i];
	}

	int temp[MAX_SIZE];
	for (size_t i = 0; i < size/2; i++) {
		temp[i] = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp[i];
	}

	cout << endl;
	cout << "New arr:\n";
	for (size_t i = 0; i < size; i++) {
		cout << arr[i];
	}

	return 0;
}