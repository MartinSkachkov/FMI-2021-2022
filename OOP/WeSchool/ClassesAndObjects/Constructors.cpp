#include <iostream>
using namespace std;
//A constructor in C++ is a special method that is automatically 
//called when an object of a class is created.
class Car {
public:
	int year;
	string model;
	string brand;
	//Inside the constructor we set the attributes equal to 
	//the constructor parameters
	Car(string m, string b, int y) {
		model = m;
		brand = b;
		year = y;
	}
	//The constructor has the same name as the class, it is always public, 
	//and it does not have any return value.

	/* other way
	 Car(string m, string b, int y); // declare the constructor
	*/
};

/*
call the constructor
Car::Car(string m, string b, int y) {
	model = m;
	brand = b;
	year = y;
}*/

int main() {
	// Create Car objects and call the constructor with different values
	Car myObj("X5", "BMW", 1995);
	Car myObj2("X6", "BMW", 2000);


	cout << myObj.model << endl << myObj.year << endl << myObj.brand << endl;
	cout << myObj2.model << endl << myObj2.year << endl << myObj2.brand << endl;
	return 0;
}
