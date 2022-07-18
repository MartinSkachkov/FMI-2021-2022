#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	unsigned int firstSide, secondSide;
	cin >> firstSide >> secondSide;
	if (firstSide == secondSide) {
		cout << "square\n";
	}
	else {
		cout << "rectangular\n";
	}

	unsigned int perimeter = 2 * (firstSide + secondSide);
	cout << "Perimeter is: " << perimeter << endl;
	unsigned int area = firstSide * secondSide;
	cout << "Area is: " << area << endl;
	return 0;
}