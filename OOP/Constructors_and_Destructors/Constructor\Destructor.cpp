#include <iostream>
using namespace std;

struct Student {
	char* name;
	int age;

	//constructor
	Student(const char* name, int age) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}

	void print() const {
		cout << "Name: " << this->name << "\n Age:" << this->age;
	}

	//destructor to delete the allocated memory
	~Student() {
		delete[] name;
	}
};

int main() {
	cout << "Name: ";
	char str[1024];
	cin.getline(str, 1024);

	cout << "Age: ";
	int age;
	cin >> age;

	Student student(str, age); //initialize student
	student.print();

}
