#include "Building.h"
#include <cstring>
#include <iostream>
using namespace std;

void Building::copy(const Building &other) {
    mHeight = other.mHeight;
    mArea = other.mArea;
    mAddress = new char[strlen(other.mAddress) + 1];
    strcpy(mAddress, other.mAddress);
}

void Building::free() {
    delete[] mAddress;
}

Building::Building(double height, double area, const char *address)
    : mHeight(height), mArea(area) {
    mAddress = new char[strlen(address) + 1];
    strcpy(mAddress, address);
}

Building::Building(const Building &other) {
    copy(other);
}

Building &Building::operator=(const Building &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

Building::~Building() {
    free();
}

ostream &operator<<(ostream &out, const Building &b) {
    out << "======Building Info======\n";
    out << "Address: " << b.mAddress << '\n';
    out << "Area: " << b.mArea << '\n';
    out << "Height: " << b.mHeight << '\n';
    return out;
}

istream &operator>>(istream &in, Building &b) {
    cout << "======Building Information======\n";

    cout << "Address: ";
    char buff[1024];
    in.getline(buff, 1024);
    b.mAddress = new char[strlen(buff) + 1];
    strcpy(b.mAddress, buff);

    cout << "Area: ";
    in >> b.mArea;

    cout << "Height: ";
    in >> b.mHeight;

    return in;
}