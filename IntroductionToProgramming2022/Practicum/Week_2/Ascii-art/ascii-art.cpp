#include <iostream>
using namespace std;

int main() {
	char letter;
	cout << "Enter letter: ";
	cin >> letter;
	switch (letter) {
	case 'a':
		cout << "    //   " << endl;
		cout << "  // //  " << endl;
		cout << " /////// " << endl;
		cout << "//     //" << endl;
		break;
	case 'b':
		cout << " /////   " << endl;
		cout << " //  //  " << endl;
		cout << " /////   " << endl;
		cout << " //  //  " << endl;
		cout << " /////   " << endl;
		break; //stops it from going on
	case 'c':
		cout << "  /////  " << endl;
		cout << " //      " << endl;
		cout << " //      " << endl;
		cout << " //      " << endl;
		cout << "  /////  " << endl;
		break;
	};
	return 0;
}
