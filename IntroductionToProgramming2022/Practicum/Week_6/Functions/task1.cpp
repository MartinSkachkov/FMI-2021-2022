#include <iostream>
using namespace std;

bool isPrime(unsigned int num) {
	if (num == 0 || num == 1) {
		return false;
	}
	for (size_t i = 2; i <= num/2; i++) {
		if (num % i == 0) { //condition not to be prime
			return false;
		}
	}
	return true;
}

int main() {
	unsigned int num;
	cout << "Number: ";
	cin >> num;

	cout << boolalpha << "Is Prime? " << isPrime(num);
	return 0;
}
