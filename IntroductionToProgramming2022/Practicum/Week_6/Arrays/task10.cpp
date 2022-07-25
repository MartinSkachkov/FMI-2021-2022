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
		cout << fixed << setprecision(2) << arr[i] << ' ';
	}
}

int main() {
	int arr[MAX_SIZE], n;
	cout << "N: ";
	cin >> n;

	initArr(arr, n);

	int m;
	do {
		cout << "M: ";
		cin >> m;
	} while (m >= n || m < 0);

	if (arr[m] < m) {
		arr[m] = arr[m] * arr[m];
	}
	else if (arr[m] == m) {
		arr[m] = -arr[m];
	}
	else if (arr[m] > m) {
		arr[m] = arr[m - 1];
	}
	else {
		cout << "invalid operation.";
	}

	printArr(arr, n);
	return 0;
}