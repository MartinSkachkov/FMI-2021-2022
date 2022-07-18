#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	unsigned int n, m;
	cin >> n >> m;
	
	//cout << boolalpha << (n % 10 == m || n / 10 % 10 == m || n / 100 % 10 == m);
	if (n%10 == m) {
		cout<<"true";
	}
	else if (n / 10 % 10 == m) {
		cout << "true";
	}
	else if (n / 100 % 10 == m) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}