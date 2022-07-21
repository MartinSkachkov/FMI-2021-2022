#include <iostream>
using namespace std;

int main() {
	int x, result, k;
	cout << "x: ";
	cin >> x;
	cout << "k: "; //34
	cin >> k;
	result = x; //f1(x) = x;

	for (size_t i = 2; i <= k + 1; i++) {
		if (result % 2 == 0) {
			result /= 2;
		}
		else {
			result = 3 * result + 1;
		}
	}
	cout << "Result: " << result;
	return 0;
}
