#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int num;
	cout << "Num: "; //123
	cin >> num;

	//without loop
	int lastDigit = num % 10; //3
	int middleDigit = num / 10 % 10; //12 % 10 = 2
	int firstDigit = num / 100 % 10; //1 % 10 = 1 

	cout << lastDigit << "-" << middleDigit << "-" << firstDigit << endl;

	//with loop
	int copyNum = num, rem;
	while (copyNum != 0) {
		rem = copyNum % 10;
		copyNum /= 10;
		cout << rem << "-";
	}
}