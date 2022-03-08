#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SIZE 1024

/*This program will replace whatever file you specify, destroying its old
contents. Therefore, when you run it, be careful not to enter the name of an
existing file unless you don’t mind losing that file’s contents*/

int main() {
	//write to the disk file output.txt
	//enter the dir and name of the file
	char filename[MAX_SIZE];
	cout << "Enter a file name: ";
	cin.getline(filename, MAX_SIZE);

	ofstream fout(filename);//open the file for writing

	//validate opening
	if (!fout.is_open())
	{
		cout << "Error";
		return 1;
	}
	else {
		cout<< filename << " was opened";
	}

	//user input
	char input[MAX_SIZE];
	cin >> input;

	fout << input << '\n' << "That was it!";//write the info to the file

	//close the file
	fout.close();
	return 0;
}
