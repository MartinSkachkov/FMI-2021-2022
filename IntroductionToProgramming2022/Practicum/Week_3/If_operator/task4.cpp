#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	unsigned int n;
	cin >> n;

	unsigned int lastDigit = n % 10;
	unsigned int middleDigit = n/10 % 10;
	unsigned int firstDigit = n/100 % 10;

	if (firstDigit <= middleDigit && middleDigit <= lastDigit) {
		cout << "true";
	}
	else {
		cout << "false";
	}

	return 0;
}