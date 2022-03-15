#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

struct Student {
	char* name;
	int fn;
	int age;
};

void saveStudentInfo(ofstream& out, const Student& student) {
	//out.write((const char*)&student, sizeof(student)); НЕ РАБОТИ ТАКА
	size_t nameLength = strlen(student.name) + 1;
	out.write((const char*)&nameLength, sizeof(nameLength));
	out.write(student.name, nameLength);
	out.write((const char*)&student.fn, sizeof(student.fn));
	out.write((const char*)&student.age, sizeof(student.age));
}

void loadStudentInfo(ifstream& in, Student& student) {
	//in.read((char*)&student, sizeof(student)); НЕ РАБОТИ ТАКА
	size_t nameLength;
	in.read((char*)&nameLength, sizeof(nameLength));
	in.read(student.name, nameLength);
	in.read((char*)&student.fn, sizeof(student.fn));
	in.read((char*)&student.age, sizeof(student.age)); 
}

int main() {
	Student student1;

	{char string[1024];
	cout << "Student1 name: ";
	cin.getline(string, 1024);

	student1.name = new char[strlen(string) + 1];
	strcpy_s(student1.name, strlen(string) + 1, string);

	cout << "FN: ";
	cin >> student1.fn;

	cout << "Age: ";
	cin >> student1.age;

	ofstream out("random.txt", ios::binary);

	if (!out.is_open()) {
		cout << "Error";
		delete[] student1.name;
		return 1;
	}

	saveStudentInfo(out, student1);
	delete[] student1.name;
	out.close(); }

	{ifstream in("random.txt", ios::binary);

	if (!in.is_open()) {
		cout << "Error";
		delete[] student1.name;
		return 1;
	}

	loadStudentInfo(in, student1);
	cout << student1.name << ' ' << student1.fn << ' ' << student1.age;
	delete[] student1.name;
	in.close(); }

	return 0;
}
