#include <iostream>
using namespace std;

void smallOrBig(char letter) {
	if (letter >= 'a' && letter <= 'z') {
		cout << "Small letter " << letter << endl;
	}
	else if (letter >= 'A' && letter <= 'Z') {
		cout << "Big letter " << letter << endl;
	}
	else {
		cout << "Invalid letter input!";
	}
}

int main() {
	char letter;
	cout << "Letter: ";
	cin >> letter;

	smallOrBig(letter);
	return 0;
}
