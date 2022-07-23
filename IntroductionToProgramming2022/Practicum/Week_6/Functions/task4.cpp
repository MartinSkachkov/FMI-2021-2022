#include <iostream>
#define MAX_SIZE 1024
using namespace std;

void initArr(int* arr, int size) {
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

bool isPalindrome(int number) {
	int numCopy = number, rem, rev = 0;
	while (numCopy != 0) {
		rem = numCopy % 10;
		rev = rev * 10 + rem;
		numCopy /= 10;
	}

	if (rev == number) {
		return true;
	}
	else {
		return false;
	}
}

bool allPalindrome(int arr[], int size) {
	unsigned int palindromesCount = 0;
	for (size_t i = 0; i < size; i++) {
		if (isPalindrome(*(arr + i))) {
			palindromesCount++;
		}
	}

	if (palindromesCount == size) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int arr[MAX_SIZE];
	unsigned int size;
	cout << "Arr size: ";
	cin >> size;

	initArr(arr, size);
	cout << "All arr members are palindromes? " << boolalpha << allPalindrome(arr, size);

	return 0;
}
