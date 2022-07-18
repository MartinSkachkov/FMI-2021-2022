#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (size_t i = 1; i <= n; i++) {
		for (size_t j = 1; j <= i; j++) {
			cout << "#";
		}
		cout << endl;
	}
	cout << endl;

	for (size_t i = 1; i <= n; i++) {
		for (size_t k = 1; k <= (n - i); k++) {
			cout << " ";
		}
		for (size_t j = 1; j <= i; j++) {
			cout << "#";
		}
		cout << endl;
	}
	cout << endl;

	//   #
	//  ##
	// ###
	//####

	for (size_t i = 0; i <= n; i++) {
		for (size_t j = n - i; j >= 1; j--) {
			cout << '#';
		}
		cout << endl;
	}

	//####
	//###
	//##
	//#
	return 0;
}