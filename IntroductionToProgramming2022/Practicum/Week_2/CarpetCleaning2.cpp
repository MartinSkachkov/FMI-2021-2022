#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "Frank's Carpet Cleaning Service\n"
		<< "Charges:\n"
		<< "$25 per small room\n"
		<< "$35 per large room\n"
		<< "Sales tax rate is 6 %\n"
		<< "Estimates are valid for 30 days\n";

	unsigned int smallRrooms;
	cout << "Estimate receipt for carpet cleaning service:\n";
	cout << "Number of small rooms: ";
	cin >> smallRrooms;

	unsigned int largeRrooms;
	cout << "Number of large rooms: ";
	cin >> largeRrooms;

	const unsigned int pricePerSmallRoom = 25;
	const unsigned int pricePerLargeRoom = 35;

	cout << "Price per small room : $25\n";
	cout << "Price per large room : $35\n";

	unsigned int cost = pricePerLargeRoom * largeRrooms + pricePerSmallRoom * smallRrooms;
	cout << "Cost: $" << cost << endl;

	const double tax = 6.0 / 100 * cost;
	cout << "Tax: $" << fixed << setprecision(2) << tax << endl;
	cout << "======================\n";
	cout << "Total estimate: $" << tax + cost;

	return 0;
}
