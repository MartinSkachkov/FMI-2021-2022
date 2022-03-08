#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SIZE 1024

int main() {
	//reading a file
	ifstream fread("output.txt");

	//validate if the file can be opened
	if (!fread.is_open())
	{
		cout << "Error";
		return 1;
	}

	//itterate through the whole file till you meet the end of the file
	while (!fread.eof()) {
		char read[MAX_SIZE];
		fread.getline(read, MAX_SIZE);
		cout << read << endl;
	}

	fread.close();
	return 0;
}
