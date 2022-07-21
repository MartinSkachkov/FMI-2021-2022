#include <iostream>
using namespace std;

bool isPrime(int num) {
	for (size_t i = 2; i <= num /2; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

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

	cout << "Primes:\n";
	unsigned int primeCounter = 0;
	for (size_t i = 0; i < size; i++) {
		if (isPrime(arr[i])) {
			primeCounter++;
			cout << arr[i] << ' ';
		}
	}

	cout << endl;
	cout << "Counter: " << primeCounter << endl;
	return 0;
}