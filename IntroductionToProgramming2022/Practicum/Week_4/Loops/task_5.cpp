#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;

	do {
		cin >> n;
	} while (n < 0);

	int f1 = 0, f2 = 1, temp;
	if (n == 0) {
		cout << f1;
	}
	else if (n == 1) {
		cout << f2;
	}
	else {
		while (n > 1) {
			temp = f2;
			f2 += f1;
			f1 = temp;
			n--;
		}
		cout << f2;
	}
	return 0;
}