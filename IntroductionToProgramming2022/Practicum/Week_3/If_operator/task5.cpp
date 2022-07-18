#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	unsigned int n, nCopy, rem, sum = 0, rev = 0;
	cin >> n;
	nCopy = n;

	while (nCopy !=0) {
		rem = nCopy % 10;
		rev = rev * 10 + rem;
		nCopy /= 10;
	}

	rem = 0;
	while (rev != 0) {
		rem = rev % 10;
		sum += rem;
		cout << rem;
		rev /= 10;
	}
	cout << endl;
	cout << sum;

	return 0;
}