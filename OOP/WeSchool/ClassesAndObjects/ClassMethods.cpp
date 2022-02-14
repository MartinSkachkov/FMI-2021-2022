#include <iostream>
using namespace std;

class Car {
public:
	/* One way
	int maxSpeed(int speed) {
		return speed;
	}*/

	int maxSpeed(int speed);
};

int Car::maxSpeed(int speed) {
	return speed;
}

int main() {
	Car myObj;

	int speed;
	cout << "Enter the speed: ";
	cin >> speed;

	cout << myObj.maxSpeed(speed);
	return 0;
}
