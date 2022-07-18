#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double r, s, p;
	const double pi = 3.14;
	cout << "Radius: ";
	cin >> r;

	s = pi * pow(r, 2);
	cout << "S: " << fixed << setprecision(2) << s << endl;

	p = 2 * pi * r;
	cout << "P: " << fixed << setprecision(2) << p << endl;
}