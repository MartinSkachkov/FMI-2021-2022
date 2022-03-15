#include <iostream>
#include <fstream>
using namespace std;

struct File {
	bool x;
	int y;
};

int main() {
	File file = { true, 25 };

	//write
	{ofstream out("random.bat", ios::binary);

	if (!out.is_open()) {
		cout << "Error";
		return 1;
	}

	out.write((const char*)&file, sizeof(File));
	out.close(); }

	//read
	{ifstream in("random.txt", ios::binary);

	if (!in.is_open()) {
		cout << "Error";
		return 1;
	}

	in.read((char*)&file, sizeof(File));
	in.close();
	cout << file.x << ' ' << file.y << endl; }

	return 0;
}
