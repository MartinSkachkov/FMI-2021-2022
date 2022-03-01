#include <iostream>
using namespace std;

struct Distance {
	int feet;
	float inches;
};

struct Room {
	Distance length;
	Distance width;
};

int main() {
	Room dining; //define a room

	cin >> dining.length.feet;
	cin >> dining.length.inches;
	cin >> dining.width.feet;
	cin >> dining.width.inches;

	float l = dining.length.feet + dining.length.inches / 12;
	float w = dining.width.feet + dining.width.inches / 12;

	cout << "Dining room area is " << l * w
		<< " square feet\n";
	return 0;
}
