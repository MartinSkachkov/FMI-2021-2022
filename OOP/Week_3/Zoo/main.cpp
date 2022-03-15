#include <iostream>
#include "Zoo.h"
#define MAX_SIZE 1024
using namespace std;

void Animal::initialize() {
	//Type
	cout << "Choose animal type:\n";
	cout << "1. Mammal\n";
	cout << "2. Reptile\n";
	cout << "3. Fish\n";
	cout << "4. Bird\n";
	cout << "5. Amphibian\n";
	cout << "6. Ivertebrates\n";
	cout << "7. Insect\n";
	int choice;
	cin >> choice;

	if (choice < 1 || choice > 7) {
		throw "Invalid type of animal";
		return;
	}

	this->mType = (AnimalType)choice;

	//Name
	cout << "Animal name: ";
	char string[MAX_SIZE];
	cin.ignore();
	cin.getline(string, MAX_SIZE);
	//cin >> string;

	this->mName = new char[strlen(string) + 1];
	strcpy_s(this->mName, strlen(string) + 1, string);

	//Age
	cout << "Age: ";
	cin >> this->mAge;
}

void Animal::deleteDynamics() {
	delete[] this->mName;
}

void Animal::writeToStream(ofstream& out) {
	//Всяко поле на структурата може да го разположим на отделен ред 
	//или може всяко поле да го разделим с един ' ' (това работи, само когато файлът не е двоичен)
	out << (int)this->mType << endl;
	out << strlen(this->mName) << ' ' << this->mName;
	out << this->mAge << endl;
}

void Animal::loadFromStream(ifstream& in) {
	int typeNum;
	in >> typeNum;
	
	int stringLength;
	in >> stringLength;
	in.get();// ignore the ' '

	this->mName = new char[stringLength + 1];
	in.getline(mName, stringLength);

	in >> this->mAge;
}

void Zoo::initialize() {
	//Name
	char string[MAX_SIZE];
	cout << "Zoo name: ";
	cin.getline(string, MAX_SIZE);

	this->mName = new char[strlen(string) + 1];
	strcpy_s(this->mName, strlen(string) + 1, string);

	//Animal Number
	cout << "Animal number: ";
	cin >> this->mAnimalNumber;
	cout << "Max Animal number: ";
	cin >> this->mAnimalMaxSize;

	if (this->mAnimalNumber > this->mAnimalMaxSize) {
		throw "Error";
		return;
	}

	//Animal List
	this->mAnimalList = new Animal[this->mAnimalNumber];
	for (int i = 0; i < this->mAnimalNumber; i++) {
		this->mAnimalList[i].initialize();
	}
}

void Zoo::deleteDynamic() {
	delete[] this->mName;
	for (int i = 0; i < this->mAnimalNumber; i++) {
		this->mAnimalList[i].deleteDynamics();
	}
	delete[] this->mAnimalList;
}

void Zoo::writeToStream(ofstream& out) {
	out << strlen(this->mName) << ' ' << this->mName << endl;
	out << this->mAnimalNumber << endl;
	out << this->mAnimalMaxSize << endl;
	for (int i = 0; i < mAnimalNumber; i++) {
		this->mAnimalList[i].writeToStream(out);
	}
}

void Zoo::loadFromStream(ifstream& in) {
	int nameSize;
	in >> nameSize;
	
	in.get();// ignore the ' '
	this->mName = new char[nameSize + 1];
	in.getline(this->mName, nameSize);

	in >> this->mAnimalNumber;
	in >> this->mAnimalMaxSize;

	this->mAnimalList = new Animal[this->mAnimalNumber + 1];
	for (int i = 0; i < mAnimalNumber; i++) {
		this->mAnimalList[i].loadFromStream(in);
	}
}

int main() {

	Zoo myZoo;

	try
	{
		myZoo.initialize();
	}
	catch (const char* e)
	{
		std::cerr << e << '\n';
		return 1;
	}

	ofstream outFile("myzoo.txt", ios::trunc);
	if (!outFile.is_open()){
		cout << "File couldn't be opened";
	}
	myZoo.writeToStream(outFile);

	outFile.close();

	Zoo loadedZoo;
	ifstream inFile("myzoo.txt");
	if (!inFile.is_open()){
		cout << "File couldn't be opened";
	}
	try
	{
		loadedZoo.loadFromStream(inFile);
	}
	catch (const char* e)
	{
		std::cerr << e << '\n';
		return 1;
	}
	//loadedZoo.writeToStream(inFile);

	inFile.close();

	myZoo.deleteDynamic();
	loadedZoo.deleteDynamic();

	return 0;
}
