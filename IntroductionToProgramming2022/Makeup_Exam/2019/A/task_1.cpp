#include <iostream>
using namespace std;

void encode(char* s1, char* r1, char* s2, char*& r2) {
	char letters[28] = { 0 };
	size_t asciiNum = 97;
	for (size_t i = 0; i < 26; i++) {
		letters[i] = asciiNum++;
	}
	letters[26] = ' ';
	letters[27] = 0;

	char alphabet[28] = { 0 };
	strcpy_s(alphabet, strlen(letters) + 1, letters);

	bool marked[27] = { 0 };

	for (size_t i = 0; i < strlen(s1); i++) {
		if (marked[s1[i] - 'a']) {
			if (letters[s1[i] - 'a'] != r1[i]) {
				throw "Incorrect function!";
				r2 = new char(0);
				return;
			}
		}
		letters[s1[i] - 'a'] = r1[i];
		marked[s1[i] - 'a'] = 1;
	}

	r2 = new char[strlen(s2) + 1];
	strcpy_s(r2, strlen(s2) + 1, s2);
	for (size_t i = 0; i < strlen(alphabet); i++) {
		for (size_t j = 0; j < strlen(r2); j++) {
			if (s2[j] == alphabet[i]) {
				if (marked[r2[j] - 'a']) {
					r2[j] = letters[i];
				}
				else {
					continue;
				}
			}
		}
	}
}

int main() {
	size_t s1Len;
	cout << "s1 len: ";
	cin >> s1Len;

	cout << "s1: ";
	char* s1 = new char[s1Len + 1];
	cin.ignore();
	cin.getline(s1, s1Len + 1);

	size_t r1Len;
	do {
		cout << "r1 len: ";
		cin >> r1Len;
	} while (r1Len != s1Len);

	cout << "r1: ";
	char* r1 = new char[r1Len + 1];
	cin.ignore();
	cin.getline(r1, r1Len + 1);

	size_t s2Len;
	cout << "s2 len: ";
	cin >> s2Len;

	cout << "s2: ";
	char* s2 = new char[s2Len + 1];
	cin.ignore();
	cin.getline(s2, s2Len + 1);

	char* r2 = nullptr;
	try {
		encode(s1, r1, s2, r2);
	}
	catch (const char* err) {
		cout << err;
		return -1;
	}
	cout << "result: " << r2;

	delete[] s1;
	delete[] r1;
	delete[] s2;
	delete[] r2;
	return 0;
}
