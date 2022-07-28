#include <iostream>
using namespace std;

int countOfDivisors(int num) {
	int divisorsCounter = 0;
	for (size_t i = 2; i <= num/2; i++) {
		if (num % i == 0) {
			divisorsCounter++;
		}
	}
	return divisorsCounter;
}

bool isPrime(int num) {
	if (num == 0 || num == 1) {
		return false;
	}

	for (size_t i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int a, b;
	do {
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	} while (b < a);

	int primesCounter = 0;
	for (size_t i = a; i <= b; i++) {
		int checkIfPrime = countOfDivisors(i);
		if (isPrime(checkIfPrime)) {
			primesCounter++;
			cout << i << ' ';
		}
	}

	cout << "Primes counter: " << primesCounter;
	return 0;
}