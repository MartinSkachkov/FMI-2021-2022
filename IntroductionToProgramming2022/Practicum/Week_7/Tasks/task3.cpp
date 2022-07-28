#include <iostream>
#define MAX_SIZE 100
using namespace std;

void initArr(int* arr, int size) {
	for (size_t i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int main() {
	int n;
	cout << "N: ";
	do {
		cin >> n;
	} while (n < 1'000'000);

	int arr[MAX_SIZE];
	initArr(arr, n);

	bool isResult;
	for (size_t k = n - 2; k >= 1; k--) {
		isResult = true;
		for (size_t i = 0; i < n - k; i++) {
			if (abs(arr[i] - arr[i + k]) != k) {
				isResult = false;
				break;
			}
		}
		if (isResult) {
			cout << k << '\n';
			break;
		}
	}

	if (!isResult) {
		cout << "No solution\n";
	}

	return 0;
}