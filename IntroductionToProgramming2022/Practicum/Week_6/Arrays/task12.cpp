#include <iostream>
#define MAX_SIZE 100
using namespace std;

void initArr(int* arr, unsigned int size) {
	cout << "Arr init: ";
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void printArr(int* arr, unsigned int size) {
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
}

int main() {
	int arr[MAX_SIZE];
	int n;
	do {
		cin >> n;
	} while (n < 1 || n>100);

	initArr(arr, n);

	for (size_t i = 0; i < n - 1; i++) {
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
			cout << arr[i];
		}
	}

	return 0;
}