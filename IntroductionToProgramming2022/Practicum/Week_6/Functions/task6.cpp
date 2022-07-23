#include <iostream>
using namespace std;

bool devisibleByThree(int num) {
	int numCopy = num, sum = 0, rem;
	while (numCopy != 0) {
		rem = numCopy % 10;
		sum += rem;
		numCopy /= 10;
	}

	return sum % 3 == 0;
}

int main() {
	int num;
	cout << "num: ";
	cin >> num;

	cout << num << " digits are  / 3 = " << boolalpha << devisibleByThree(num);

	return 0;
}
