#include <iostream>
using namespace std;

int main() {
	double money;
	cout << "Money: ";
	cin >> money;

	unsigned int dollar{ 0 }, quarter{ 0 }, dime{ 0 }, nickel{ 0 }, penny{ 0 };

	do {
		if (money >= 100) {
			dollar++;
			money -= 100;
		}
		else if (money >= 25) {
			quarter++;
			money -= 25;
		}
		else if (money >= 10) {
			dime++;
			money -= 10;
		}
		else if (money >= 5) {
			nickel++;
			money -= 5;
		}
		else if (money >= 1) {
			penny++;
			money -= 1;
		}
	} while (money != 0);

	cout << "Change\n";
	cout << "dollar: " << dollar << endl
		<< "quarter: " << quarter << endl
		<< "dime: " << dime << endl
		<< "nickel: " << nickel << endl
		<< "penny: " << penny << endl;
	return 0;
}
