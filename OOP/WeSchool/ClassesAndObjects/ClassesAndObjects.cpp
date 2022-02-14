#include <iostream>
using namespace std;

class MyClass {// The class
public: // access specifier
	int myNum; // Attribute (int variable)
	char str[20]; // Attribute (string variable)
};

int main() {
	MyClass myObject; // creating an object of MyClass

	// Access attributes and set values
	myObject.myNum = 19;
	cin.getline(myObject.str, 20);

	cout << myObject.str << myObject.myNum;
	return 0;
}
