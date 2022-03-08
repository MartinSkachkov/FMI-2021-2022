#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SIZE 1024

int main() {
	char file_name[MAX_SIZE];
	cout << "Enter the file location: ";
	cin.getline(file_name, MAX_SIZE);

	ifstream file_read(file_name);

	if (!file_read.is_open())
	{
		cout << file_name << "couldn't be opened";
		return 1;
	}

	while (!file_read.eof())
	{
		char reader[MAX_SIZE];
		file_read.getline(reader, MAX_SIZE);
		cout << reader << endl;
	}

	file_read.close();
	return 0;
}
