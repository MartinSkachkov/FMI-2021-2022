#include <iostream>
using namespace std;

int main() {
	double x, y;
	cout << "Enter x and y: ";
	cin >> x >> y;

	// полукръг с център (0,0) и радиус 2, над абцисната ос
	bool c1 = x * x + y * y <= 4 && y >= 0;

	// кръг с център (-1,0) и радиус 1
	bool c2 = (x + 1) * (x + 1) + y * y <= 1;

	// кръг с център (1,0) и радиус 1, без контур
	bool c3 = (x - 1) * (x - 1) + y * y < 1;

	if ((c1 || c2) && !c3) {
		cout << '(' << x << ',' << y << ')' << "is in the area!";
	}
	else {
		cout << "point isn't in the area!";
	}
	return 0;
}