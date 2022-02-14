#include <iostream>
using namespace std;

class Car {
public:
	int year;
	char model[10];
	char brand[10];
};

int main() {
	Car firstCar, secondCar; // object

	firstCar.year = 1995;
	cin.getline(firstCar.brand, 10);
	cin.getline(firstCar.model, 10);

	secondCar.year = 2000;
	cin.getline(secondCar.brand, 10);
	cin.getline(secondCar.model, 10);

	cout << firstCar.year << endl << firstCar.brand << endl << firstCar.model << endl;
	cout << secondCar.year << endl << secondCar.brand << endl << secondCar.model << endl;
	return 0;
}
