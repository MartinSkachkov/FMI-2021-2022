#include <iostream>
using namespace std;

int main() {
	double x, y, centerX, centerY, r;
	cout << "Enter x and y: ";
	cin >> x >> y;

	cout << "Center of circle: ";
	cin >> centerX >> centerY;

	cout << "R: ";
	cin >> r;

	if ((x-centerX)* (x - centerX) + (y-centerY)*(y-centerY) <= r*r) {
		cout << '(' << x << ',' << y << ')' << "is in circle!";
	}
	else {
		cout << "point isn't in the circle!";
	}
	return 0;
}