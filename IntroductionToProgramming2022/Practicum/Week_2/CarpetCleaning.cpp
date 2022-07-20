#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	unsigned int rooms;
	cout << "Estimate receipt for carpet cleaning service:\n";
	cout << "Number of rooms: ";
	cin >> rooms;

	unsigned int pricePerMonth;
	cout << "Price per month: $";
	cin >> pricePerMonth;

	unsigned int cost = pricePerMonth * rooms;
	cout << "Cost: $" << cost << endl;

	double tax = 6.0 / 100 * cost;
	cout << "Tax: $" << fixed << setprecision(2) << tax << endl;
	cout << "======================\n";
	cout << "Total estimate: $" << tax + cost;

	return 0;
}
