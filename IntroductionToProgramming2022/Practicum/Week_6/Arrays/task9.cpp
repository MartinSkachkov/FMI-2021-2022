#include <iostream>
#define MAX_SIZE 100
using namespace std;

bool euqalArrs(int* arr1, int* arr2, unsigned int size1, unsigned int size2) {
	bool allAreContained = true;
	for (size_t i = 0; i < size1; i++) {
		bool currIsContained = false;
		for (size_t j = 0; j < size2; j++) {
			if (arr1[i] == arr2[j]) {
				currIsContained = true;
				break;
			}
			else {
				currIsContained = false;
				break;
			}
		}
		if (currIsContained) {
			allAreContained = true;
		}
		else {
			return false;
		}
	}
	return allAreContained;
}

void initArr(int* arr, unsigned int size) {
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

int main() {
	int arr1[MAX_SIZE], arr2[MAX_SIZE];
	unsigned int size1, size2;
	cout << "Size1: ";
	cin >> size1;
	cout << "Size2: ";
	cin >> size2;

	if (size1 != size2) {
		cout << "Not equal!";
		return 0;
	}

	initArr(arr1, size1);
	initArr(arr2, size2);

	cout << boolalpha << euqalArrs(arr1, arr2, size1, size2);

	return 0;
}
