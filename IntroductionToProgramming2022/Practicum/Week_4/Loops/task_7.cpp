#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned int n;
	do{
	cin >> n;
	} while (n == 0);

	double result = sqrt(n);
	for (size_t i = n-2; i >=1; i-=2) {
		result = sqrt(i - result);
	}
	cout << result;
	return 0;
}