#include <iostream>
using namespace std;

int main() {
	const int MAX_SIZE = 1024;
	int arr[MAX_SIZE];

	unsigned int size;
	do {
		cin >> size;
	} while (size < 3);

	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}

	bool arithmeticProg = true;
	bool geometricProg = true;
	int difference = arr[1] - arr[0]; //arith
	double quotient = arr[1] / arr[0]; //geo

	for (size_t i = 1; i < size; i++) {
		if (arr[i] - arr[i - 1] != difference) {
			arithmeticProg = false;
		}
		if ((double)arr[i] / arr[i - 1] != quotient) {
			geometricProg = false;
		}
	}

	if (arithmeticProg) {
		cout << "Arithmetic progression!";
	}
	else if (geometricProg) {
		cout << "Geometric progression!";
	}
	else {
		cout << "Random sequence!";
	}

	//case with only one number not included
	//solution: print only geoProg and arithProgr (not with ifs)
	return 0;
}