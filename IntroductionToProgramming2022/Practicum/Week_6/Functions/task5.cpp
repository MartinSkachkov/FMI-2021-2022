#include <iostream>
#define MAX_SIZE 1024
using namespace std;

void initArr(char* arr, int size) {
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

bool isSmallLetter(char symbol) {
	return (symbol >= 'a' && symbol <= 'z');
}

bool isCapitalLetter(char symbol) {
	return (symbol >= 'A' && symbol <= 'Z');
}


int main() {
	char arr[MAX_SIZE];
	unsigned int size;
	cout << "Arr size: ";
	cin >> size;

	initArr(arr, size);
	int smallCounter = 0, capitalCounter = 0, invalidChar = 0;
	for (size_t i = 0; i < size; i++) {
		if (isSmallLetter(arr[i])) {
			smallCounter++;
		}
		else if (isCapitalLetter(arr[i])) {
			capitalCounter++;
		}
		else { //case when numbers are entered;
			invalidChar++;
		}
	}

	cout << "Results\n";
	cout << "Small letters: " << smallCounter << endl;
	cout << "Capital letters: " << capitalCounter << endl;
	cout << "Invalid inputs: " << invalidChar << endl;

	return 0;
}