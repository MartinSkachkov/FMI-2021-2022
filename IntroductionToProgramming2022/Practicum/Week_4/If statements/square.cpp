#include <iostream>
using namespace std;

int main() {
	double x, y;
	cin >> x >> y;

	if ((x >= -1 && x <= 1) && (y <= 1 && y >= -1)) {
		cout << '(' << x << ',' << y << ')' << "is in the square!";
	}
	else {
		cout << "point isn't in the square!";
	}
	return 0;
}