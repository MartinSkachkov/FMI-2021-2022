#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	//валидация на входа за интервала [a,b]
	int a, b;
	try {
		cout << "A: ";
		cin >> a;
		cout << "B: ";
		cin >> b;
		if (a > b) {
			throw "Invalid interval!";
		}
	}
	catch (const char* err) {
		cout << err;
	}

	int sum = 0; // сумата от всички интересни числа в [a,b]
	//проверяваме дали числото е интересно
	for (int number = a; number <= b; number++) { //'а' ни е началото на интервала, а 'b' е край
		bool isInteresting = true;
		int currentNum = abs(number); //currNum = 94

		while (currentNum != 0) {
			//случай за примерен интервал [5,8]
			if (currentNum <= 10) {
				break;
			}

			int lastDigit = (currentNum % 10) % 2; //(94 % 10)%2 --> (4)%2 --> 0
			int previousDigit = ((currentNum / 10) % 10) % 2; //(94 / 10 % 10)%2 --> (9 % 10)%2 --> (9)%2 --> 1;
			if (lastDigit == previousDigit) {
				isInteresting = false;
				break;
			}
			currentNum /= 10;
		}
		if (isInteresting) {
			sum += number;
			cout << number << ' ';
		}
	}
	cout << endl << "Sum of the interesting numbers is: " << sum << endl;

	return 0;
}
