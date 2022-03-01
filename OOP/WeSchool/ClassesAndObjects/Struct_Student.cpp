#include <iostream>
using namespace std;

struct Student {
	char name[20];
	int roll;
	int group;
}s;

int main() {
	//Student s;
	cout << "Name: "; cin.getline(s.name, 20);
	cout << "Roll: "; cin >> s.roll;
	cout << "Group: "; cin >> s.group;
	cout << "Info: \n";
	cout << "Name: " << s.name << endl;
	cout << "Roll: " << s.roll << endl;
	cout << "Group: " << s.group << endl;

	return 0;
}
