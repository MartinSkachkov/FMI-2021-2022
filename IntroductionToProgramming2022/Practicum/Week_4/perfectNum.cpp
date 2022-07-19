#include <iostream>
using namespace std;

int main() {
	int n;
	do {
		cin >> n;
	} while (n < 0);

	int sum;
	for (size_t i = 1; i <= n; i++) {
		sum = 0;
		for (size_t j = 1; j <= i/2; j++) {
			// x е делител на i
			// sum = sum + x;
			if (i % j == 0) {
				sum += j;
			}
		}
		if (i == sum) {
			cout << i << ' ';
		}
	}
	return 0;
}
