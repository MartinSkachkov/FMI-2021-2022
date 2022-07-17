#include <iostream>

unsigned int sumOfDigits(unsigned int num) {
	unsigned int sum = 0, rem = 0;
	while (num!=0){
		rem = num % 10;
		sum += rem;
		num /= 10;
	}
	return sum;
}

bool isPrime(unsigned int num) {
	if (num == 0 || num == 1) {
		return false;
	}
	for (size_t i = 2; i <= num/2; i++) {
		//condition for not a prime number
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	unsigned int a, b; //[a,b]
	std::cout << "Enter A: ";
	std::cin >> a;
	std::cout << "Enter B: ";
	std::cin >> b;

	//restrictions
	if (!(99 < a && a <= b && b < 1000)) {
		std::cout << "Invalid input! Should be: 99 < A <= B < 1000";
		return -1;
	}

	unsigned int bigNum;
	bool coolNum = false;

	for (size_t lowerBound = a; lowerBound <= b; lowerBound++) {
		if (sumOfDigits(lowerBound) >= 10 && sumOfDigits(lowerBound) <=99) {
			bigNum = lowerBound; //can be omitted
			if (isPrime(bigNum) && isPrime(sumOfDigits(bigNum))) {
				coolNum = true;
				std::cout << bigNum; // becomes a cool number
			}
		}
	}

	if (!coolNum) {
		std::cout << '0';
	}
}
