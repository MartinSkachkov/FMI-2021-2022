#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, rev = 0, nCopy, rem;
	cin >> n;
	nCopy = n;

	while (nCopy != 0) {
		rem = nCopy % 10;
		rev = rev * 10 + rem;
		nCopy /= 10;
	}

	if (n == rev) {
		cout << n << " - Palindrome";
	}
	else {
		cout << n << " - Not palindrome";
	}
	return 0;
}