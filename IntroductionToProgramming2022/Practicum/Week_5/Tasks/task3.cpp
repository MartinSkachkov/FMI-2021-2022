#include <iostream>
using namespace std;

int main() {
	const int MAX_SIZE = 1000;
	int arr[MAX_SIZE];

	unsigned int size;
	do{
	cin >> size;
	} while (size > 1000);

	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int rev[MAX_SIZE];
	for (size_t i = 0; i < size; i++) {
		rev[i] = arr[size - 1 - i];
	}

	cout << "Original arr:\n";
	for (size_t i = 0; i < size; i++){
		cout << arr[i];
	}

	cout << endl;
	cout << "Reversed arr:\n";
	for (size_t i = 0; i < size; i++) {
		cout << rev[i];
	}

	return 0;
}