#include <iostream>
using namespace std;

bool checkPrime(unsigned int num) {
	if (num == 0 || num == 1) {
		return false;
	}
	for (size_t i = 2; i < num/2; i++) {
		if (num % i == 0) { //condition for not a prime num
			return false;
		}
	}
	return true;
}

int main() {
	unsigned int arr[] = { 100, 200, 31, 13, 97, 10, 20, 11 };
	int len = sizeof(arr) / sizeof(arr[0]);

	cout << "Primes:\n";
	for (size_t i = 0; i < len; i++) {
		if (checkPrime(arr[i])) {
			cout << arr[i] << ' ';
		}
	}

	cout << endl;

	cout << "Not Primes:\n";
	for (size_t i = 0; i < len; i++) {
		if (!checkPrime(arr[i])) {
			cout << arr[i] << ' ';
		}
	}
	return 0;
}
