#include<iostream>
#include "Person.h"
using namespace std;

void Person::copyFrom(const Person& source) {
	name = new char[strlen(source.name) + 1];
	strcpy_s(name, strlen(source.name) + 1, source.name);
	this->age = source.age;
}

void Person::free() {
	delete[] name;
}

Person::Person(const char* name, int age) {
	setName(name);
	setAge(age);
}

void Person::setName(const char* name) {
	if (this->name == name) return;
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Person::setAge(int age) {
	this->age = age;
}

Person::Person(const Person& source) {
	copyFrom(source);
}

Person& Person::operator=(const Person& source) {
	if (this == &source) return *this;
	free();
	copyFrom(source);
	return *this;
}

const char* Person::getName()const {
	return name;
}

int Person::getAge()const {
	return age;
}

Person::~Person() {
	free();
}

void Person::print() const {
	cout << name << ' ' << age << endl;
}
