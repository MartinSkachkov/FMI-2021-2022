#include <iostream>
using namespace std;

int main() {
	double x, y;
	cout << "Enter x and y: ";
	cin >> x >> y;

	bool c1 = x * x + y * y <= 16 && y >= 0;
	bool c2 = (x + 2) * (x + 2) + y * y <= 4;
	bool c3 = (x - 2) * (x - 2) + y * y < 4;
	bool c4 = (x + 2) * (x + 2) + y * y < 1;

	if ((c1 || c2) && !c3 && !c4) {
		cout << '(' << x << ',' << y << ')' << "is in the area!";
	}
	else {
		cout << "point isn't in the area!";
	}
	return 0;
}