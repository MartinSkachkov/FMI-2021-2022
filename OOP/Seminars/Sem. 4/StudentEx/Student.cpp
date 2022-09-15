#include "Student.h"
#include <cstring>
#include <iostream>
using namespace std;

void Student::copy(const Student &other) {
    mName = new char[strlen(other.mName) + 1];
    strcpy(mName, other.mName);
    mAge = other.mAge;
}

void Student::free() {
    delete[] mName;
}

Student::Student(const char *name, size_t age) : mAge(age) {
    mName = new char[strlen(name) + 1];
    strcpy(mName, name);
}

Student::Student(const Student &other) {
    copy(other);
}

Student &Student::operator=(const Student &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

Student::~Student() {
    free();
}

void Student::print() const {
    cout << "Name: " << mName << '\n';
    cout << "Age: " << mAge << '\n';
}

void Student::setName() {
    char buff[100] = {0};
    cout << "Name: ";
    cin.getline(buff, 100);

    mName = new char[strlen(buff) + 1];
    strcpy(mName, buff);
}

void Student::setAge() {
    cout << "Age: ";
    cin >> mAge;
}

const char *Student::getName() const {
    return mName;
}

size_t Student::getAge() const {
    return mAge;
}