#include <iostream>
using namespace std;

int nLength(int n) {
	int length = 0;
	while (n != 0) {
		length++;
		n /= 10;
	}
	return length;
}

int getFirstDigit(int n) { // pass by value which creates a copy
	int rem = 0, length = 0;
	while (n != 0) {
		rem = n % 10;
		n /= 10;
	}
	return rem;
}

void mainLogic(int& n, int& k, int length, int divisor, bool& isInfix) {
	int nCopy = n, rem = 0, newNum = 0, iterator = 0, rev = 0, newNumCopy;
	while (length != 2) {//we don't want to check the first number
		length--;
		nCopy /= divisor; // skip the last digit
		divisor = 10;
		rem = nCopy % 10;
		if (rem == k) {
			isInfix = true;
			break;
		}
		else {
			newNum = newNum * 10 + rem; // this gives us the reversed infix
			iterator++;
		}

		newNumCopy = newNum;
		if (iterator >= 2) {
			rev = 0;
			while (newNumCopy != 0) { //we reverse the infix again to get the real infix
				rem = newNumCopy % 10;
				rev = rev * 10 + rem;
				newNumCopy /= 10;
			}
		}

		if (rev == k) {
			isInfix = true;
			break;
		}
		else {
			isInfix = false;
			continue;
		}
	}
}

int main() {
	int n, k;
	cout << "n: ";
	cin >> n;
	int length = nLength(n);

	cout << "k: ";
	cin >> k;

	if (length <= 2 || n == k) {
		cout << boolalpha << false;
		return 0;
	}

	/* needed for cool printing
	int lastDigit = n % 10;
	int firstDigit = getFirstDigit(n);*/

	bool isInfix = false;
	int divisor = 10;

	mainLogic(n, k, length, divisor, isInfix); //check the first time 
	//if everithing is ok then we exit but if not we continue checking for infix

	int divisorCount = 1, lengthCopy = length;
	if (!isInfix) {
		while (lengthCopy >= divisorCount && !isInfix) {
			divisor *= 10;
			lengthCopy--;
			divisorCount++;
			mainLogic(n, k, lengthCopy, divisor, isInfix);
		}
	}
	
	if (isInfix) {
		cout << boolalpha << true;
	}
	else {
		cout << boolalpha << false;
	}

	//cout << endl << "Concatenation:\n";
	//cout << firstDigit << " o " << k << " o " << lastDigit;
	return 0;
}
