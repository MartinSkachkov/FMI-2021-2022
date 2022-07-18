#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;

	if (x >= y && x >= z) {
		cout << "X is the biggest!\n" << x;
	}
	else if (y >= x && y >= z) {
		cout << "Y is the biggest!\n" << y;
	}
	else {
		cout << "Z is the biggest!\n" << z;
	}
	return 0;
}