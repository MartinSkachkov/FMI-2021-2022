#include <iostream>
#define MAX_SIZE 1024
using namespace std;

int main() {
	int arr[MAX_SIZE];
	cout << "Size: ";
	int size;
	cin >> size;

	cout << "Initialize: ";
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "Array: ";
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	int index;
	cout << "Index: ";
	cin >> index;

	for (size_t i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;

	cout << "Deleted Array: ";
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}
