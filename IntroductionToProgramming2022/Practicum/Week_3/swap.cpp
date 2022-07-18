#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int x, y, temp;

	//с помощна променлива
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;

	temp = x;
	x = y;
	y = temp;

	cout << "X: " << x << endl << "Y: " << y << endl;

	//с аритметични операции
	x = x + y;
	y = x - y;
	x = x - y;
	cout << "X: " << x << endl << "Y: " << y << endl;
}