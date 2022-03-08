#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//write to the disk file output.txt
	ofstream fout("output.txt"); // object fout provides access to the disk file output.txt
	if (!fout.is_open())
	{
		cout << "Error";
		return -1;
	}
	int a = 5;
	int b = 10;
	//writing to fout results in sending data to the same file
	fout << a << " " << b << " " << a + b << endl;

	if (!fout.eof()) {//check if the file has ended
		cout<< "The file contains more data after the two integers!" << endl;
	}

	fout.close();
  //отиваш на папката, търсиш файла и като го отвориш a, b, a+b ще са се записали на него.
	return 0;
}
