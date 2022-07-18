#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char operation;
	cin >> operation;

	int x, y;
	cin >> x >> y;

	try{
		switch (operation) {
		case '+':
			cout<< x + y; break;
		case '-':
			cout << x - y; break;
		case '*':
			cout << x * y; break;
		case'/':
			if (y == 0) {
				cout << "cannot devide by 0";
			}
			else {
				cout << x / y;
			}
			break;
		case'%':
			if (y == 0) {
				cout << "cannot devide by 0";
			}
			else {
				cout << x % y; break;
			}
			break;
		default:
			throw "invalid operation";
			break;
		}
	}
	catch (const char *err) {
		cout << err;
	}
	return 0;
}