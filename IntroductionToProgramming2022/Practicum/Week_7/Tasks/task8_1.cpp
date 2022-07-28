#include <iostream>
#define MAX_SIZE 100
using namespace std;


int main() {
	int arr[MAX_SIZE], result[MAX_SIZE];
	int n;
	do {
		cout << "n: ";
		cin >> n;

	} while (n > 100);

	for (size_t i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int counter = 0;
	for (size_t i = 0; i < n; i++) {
		if (i % 2 == 0) {
			result[counter++] = arr[i];
		}
	}

	for (size_t i = 1; i < n; i++) {
		if (i % 2 == 1) {
			result[counter++] = arr[i];
		}
	}

	cout << "First on even positions, second on odd positions: ";
	for (size_t i = 0; i < counter; i++) {
		cout << result[i] << ' ';
	}

	return 0;
}


