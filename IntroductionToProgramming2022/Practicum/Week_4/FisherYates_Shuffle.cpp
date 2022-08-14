	#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void shuffle(int* arr, size_t n) {
	srand(time(0));
	for (size_t i = n-1; i > 0; i--) {
		int randomIndex = rand() % i + 0;
		swap(arr[i], arr[randomIndex]);
	}
}

int main() {
	size_t n;
	cout << "n: ";
	cin >> n;

	cout << "arr: ";
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++) {
		cin >> arr[i];
	}

	shuffle(arr, n);

	for (size_t i = 0; i < n; i++) {
		cout << arr[i];
	}

	delete[] arr;
	return 0;
}
