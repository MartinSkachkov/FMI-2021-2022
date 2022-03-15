#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream out("random.bat", ios::binary);

	if (!out.is_open()){
		cout << "Error";
		return 1;
	}

	int a;
	cout << "a: ";
	cin >> a;

	out.write((const char*)&a, sizeof(int)); //sizeof(int) because 'a' is int
	out.close();

	ifstream in("random.bat", ios::binary);

	if (!in.is_open()){
		cout << "Error";
		return 1;
	}

	in.read((char*)&a, sizeof(int));
	cout << a << endl;
	in.close();

	return 0;
}
