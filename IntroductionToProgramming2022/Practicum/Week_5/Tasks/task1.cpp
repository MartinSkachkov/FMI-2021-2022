#include <iostream>
using namespace std;

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

	int min= INT16_MAX, max= INT16_MIN;
	for (size_t i = 0; i < size; i++){
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	cout << "MAX: " << max << endl;
	cout << "MIN: " << min << endl;
	return 0;
}