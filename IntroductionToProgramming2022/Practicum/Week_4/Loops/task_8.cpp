#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int toBinary = 0;
	int order = 1;
	while (n > 0) {
		toBinary += order * (n % 2);
		n /= 2;
		order *= 10;
	}
	cout<<toBinary;
	return 0;
}