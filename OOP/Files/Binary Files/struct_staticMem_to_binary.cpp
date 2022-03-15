#include <iostream>
#include <fstream>
using namespace std;

struct Student {
	char name[25];
	int fn;
	int age;
};

int main() {
	Student student;

	{cout << "Name: ";
	cin.getline(student.name, 25);
	cout << "FN: ";
	cin >> student.fn;
	cout << "Age: ";
	cin >> student.age;

	ofstream out("random.bat", ios::binary);

	if (!out.is_open()){
		cout << "Error";
		return 1;
	}

	out.write((const char*)&student, sizeof(student));
	out.close(); }

	{ifstream in("random.bat", ios::binary);

	if (!in.is_open()) {
		cout << "Error";
		return 1;
	}

	in.read((char*)&student, sizeof(student));
	cout << student.name << ' ' << student.fn << ' ' << student.age << endl;
	in.close(); }

	return 0;
}
