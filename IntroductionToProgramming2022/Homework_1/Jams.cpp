#include <iostream>
using namespace std;

int main() {
	//number of barcodes = digits / 8
	int digits;
	do {
		cout << "Enter the number of digits: ";
		cin >> digits;
	} while (digits <= 0 || digits % 8 != 0);

	int jamCount = digits / 8, blueberryJam = 0, peachJam = 0, shipkaJam = 0, invalidCode = 0;

	cout << "Enter the digits: ";
	for (size_t i = 0; i < jamCount; i++) {
		//entering the barcode for each jam
		int countryCode;
		for (size_t code = 0; code < 3; code++) {
			cin >> countryCode;
		}

		int jamBarcode = 0 , jamDigits;
		for (size_t digit = 0; digit < 4; digit++) {
			cin >> jamDigits;
			jamBarcode = jamBarcode * 10 + jamDigits;
		}
		if (jamBarcode % 7 == 0) {
			blueberryJam++;
		}
		else if (jamBarcode % 13 == 0) {
			peachJam++;
		}
		else if (jamBarcode % 17 == 0) {
			shipkaJam++;
		}
		else {
			invalidCode++;
		}

		int control;
		for (size_t i = 0; i < 1; i++) {
			cin >> control;
		}
	}

	//results
	cout << "Blueberry Jam: " << blueberryJam << endl;
	cout << "Shipka Jam: " << shipkaJam << endl;
	cout << "Peach Jam: " << peachJam << endl;
	cout << "Invalid Jam: " << invalidCode << endl;

	return 0;
}
