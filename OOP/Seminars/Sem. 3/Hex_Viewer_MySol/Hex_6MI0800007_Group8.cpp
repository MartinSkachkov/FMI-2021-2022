#include <fstream>
#include <iostream>
#define MAX_SIZE 1024
using namespace std;

size_t getFileSize(fstream& fin) {
	size_t currentPosition = fin.tellg(); //returns the get pointer index(default 0)
	fin.seekg(0, ios::end); //move the get pointer to the end
	size_t size = fin.tellg(); //returns the number of bytes

	fin.seekg(currentPosition);//set it back to 0
	return size;
}

char* byteToHex(char number) { //take 1 byte(char) and convert it to hex
	char* hexNum = new char[3]{ "00" };

	size_t i = strlen(hexNum) - 1;
	while (number != 0) {
		int temp = number % 16;

		if (temp < 10) {
			hexNum[i] = temp + 48;
		}
		else {
			hexNum[i] = temp + 55;
		}

		i--;
		number /= 16;
	}
	return hexNum;
}

void view(char* data, const int fileSize) {
	for (size_t i = 0; i < fileSize; i++){
		cout << byteToHex(data[i]) << ' ';
	}
	cout << endl;
	for (size_t i = 0; i < fileSize; i++) {
		if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z')) {
			cout << data[i] << ' ';
		}
		else {
			cout << '.' << ' ';
		}
	}
	cout << endl;
}

void change(char* data, const int fileSize) {
	int index;
	cout << endl << "index: ";
	cin >> index;

	int change;
	cout << "change with: ";
	cin >> change;
	
	int reversedChange = 0, original = change, remainder;
	while (original != 0) {
		remainder = original % 10;
		reversedChange = reversedChange * 10 + remainder;
		original /= 10;
	}

	int hexNum = 0, rem;
	do{
		rem = (char)reversedChange % 10;
		hexNum = hexNum * 16 +	rem;
		reversedChange = (char)reversedChange/ 10;
	} while (reversedChange!=0);

	for (size_t i = 0; i < fileSize; i++){
		if(index == i){
			data[i] = hexNum;
			cout << "Operation successfully executed!\n";
		}
	}
}

void remove(char*& data, int& fileSize) {
	fileSize--;
	char* removedData = new char[fileSize + 1];
	for (int i = 0; i < fileSize; i++) {
		removedData[i] = data[i];
	}
	removedData[fileSize] = 0;
	delete[] data;
	data = removedData;
}

void add(char*& data, int& fileSize) {
	int byte;
	cout << "Choose a symbol to add: ";
	cin >> byte;
	
	fileSize++; //increment the size with one byte
	char* newData = new char[fileSize + 1]; // +1 for \0
	strcpy_s(newData, fileSize, data);
	newData[fileSize - 1] = byte; //on position 4 add a symbol
	newData[fileSize] = 0; //\0 for the last position
	delete[] data;
	data = newData; //set data to point to newData
}

void save(fstream& fout, char* data, const int& fileSize) {
	fout.write((const char*)data, fileSize);
	cout << "Successfully saved in the same file!\n";
}

void saveAs(char* data, const int& fileSize) {
	cin.ignore();
	char newFileName[MAX_SIZE];
	cout << "Save as: ";
	cin.getline(newFileName, MAX_SIZE);

	ofstream newFile(newFileName, ios::binary | ios::out);

	if (!newFile.is_open()) {
		cout << "Couldn't open the file!\n";
		return;
	}
	else {
		cout << "Saving...\n";
	}

	newFile.write((const char*)data, fileSize);
	cout << "Saved!\n";
	newFile.close();
}

int main() {
	//write
	int x = 25409;
	ofstream file("myData.dat", ios::binary);
	file.write((const char*)&x, sizeof(x));
	file.close();

	//read
	cout << "Enter file path (C:\\Users\\User\\source\\repos\\HexViewer\\HexVeiwer\\myData.dat or sth like that) :\n";
	char fileName[MAX_SIZE];
	cin.getline(fileName, MAX_SIZE);
	//cin.ignore();
	fstream fin(fileName, ios::binary | ios::in | ios::out);

	int fileSize = getFileSize(fin);
	if (!fin.is_open()) {
		cout << "Error";
		return 1;
	}
	else {
		cout << "File loaded successfully! " << "Size: " << fileSize << endl;
	}

	char* data = new char[fileSize+1]; //+1 for \0
	fin.read(data, fileSize);

	view(data, fileSize);
	change(data, fileSize);
	view(data, fileSize);
	add(data, fileSize);
	remove(data, fileSize);
	view(data, fileSize);
	save(fin, data, fileSize);//save in the same file
	saveAs(data, fileSize);

	delete[] data;
	fin.close();
	return 0;
}