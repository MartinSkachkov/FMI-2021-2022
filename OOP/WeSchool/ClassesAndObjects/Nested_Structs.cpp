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
	
	//dining = { {13,6.5}, {10,0.0} }; another way of initializing
	
	cin >> dining.length.feet; //13
	cin >> dining.length.inches; //6.5
	cin >> dining.width.feet; //10
	cin >> dining.width.inches; //0.0

	float l = dining.length.feet + dining.length.inches / 12;
	float w = dining.width.feet + dining.width.inches / 12;

	cout << "Dining room area is " << l * w
		<< " square feet\n";
	return 0;
}
