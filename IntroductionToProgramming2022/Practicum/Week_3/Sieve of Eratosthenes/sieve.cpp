#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	bool arr[100];
	bool flag;

	//mark all elements as true(all are prime)
	for (size_t i = 0; i < 100; i++) {
		arr[i] = true;
	}

	cout << "\n Prime Numbers from 1 to 100 are : \n";
	// implementation of Sieve of Eratosthenes algorithm

	for (size_t i = 2; i <= 50; i++) {
		if (arr[i] == true) {
			//make all multiples as false
			for (size_t j = 2*i; j < 100; j = j+i) {
				arr[j] = false;
			}
		}
	}

	//print
	for (size_t i = 0; i < 100; i++) {
		if (arr[i] == true) {
			cout << i << " ";
		}
	}

	return 0;
}
