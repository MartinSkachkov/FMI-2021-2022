#include <iostream>
#include <cmath>
using namespace std;

int main() {
	for (size_t i = 1000; i <= 9999; i++) {
		if (i / 1000 + (i / 100 % 10) == (i / 10 % 10) + i % 10) {
			cout << i << ' ';
		}
	}

	return 0;
}