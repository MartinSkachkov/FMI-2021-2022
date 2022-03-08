#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SIZE 1024

void printFile(const char* file_name) {
	ifstream file(file_name);

	if (!file.is_open())
	{
		cout << file_name << "couldn't be open!";
	}

	while (!file.eof())
	{
		char reader[MAX_SIZE];
		file.getline(reader, MAX_SIZE);
		cout << reader << endl;
	}
}

bool copyFiles(const char* source_loc, const char* dest_loc) {
	ifstream file_read(source_loc);
	ofstream file_write(dest_loc);

	if (!file_read.is_open() || !file_write.is_open())
	{
		return false;
	}

	while (!file_read.eof())
	{
		char line[MAX_SIZE];
		file_read.getline(line, MAX_SIZE);
		file_write << line << endl;
	}

	file_read.close();
	file_write.close();
	return true;
}

int main() {
	char source_loc[MAX_SIZE];
	cout << "Source: ";
	cin.getline(source_loc, MAX_SIZE);

	char dest_loc[MAX_SIZE];
	cout << "Destination: ";
	cin.getline(dest_loc, MAX_SIZE);

	if (copyFiles(source_loc,dest_loc))
	{
		cout<<"Succesfully copied!\n";
		void(printFile(dest_loc));
	}
	else
	{
		cout << "Error while copying!";
	}


	return 0;
}
