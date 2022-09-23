#include "Person.h"
#include <cstring>
#include <iostream>
using namespace std;

void Person::free() {
    delete[] mName;
}

void Person::copy(const Person &other) {
    mName = new char[strlen(other.mName) + 1];
    strcpy(mName, other.mName);

    mAge = other.mAge;
}

Person::Person(const char *name, size_t age) : mAge(age) {
    mName = new char[strlen(name) + 1];
    strcpy(mName, name);
}

Person::Person(const Person &other) {
    copy(other);
}

Person &Person::operator=(const Person &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

Person::~Person() {
    free();
}

std::ostream &operator<<(std::ostream &out, const Person &p) {
    out << "Name: " << p.mName << '\n';
    out << "Age: " << p.mAge << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Person &p) {
    char buff[100];
    in.getline(buff, 100);

    p.free();
    p.mName = new char[strlen(buff) + 1];
    strcpy(p.mName, buff);

    in >> p.mAge;
    return in;
}