#include "House.h"
#include <cstring>
#include <iostream>
using namespace std;

void House::copy(const House &other) {
    mFloors = other.mFloors;
    mOwner = new char[strlen(other.mOwner) + 1];
    strcpy(mOwner, other.mOwner);
}

void House::free() {
    delete[] mOwner;
}

House::House() : Building(0, 0, "None"), mFloors(0) {
    mOwner = new char[strlen("None") + 1];
    strcpy(mOwner, "None");
}

House::House(double height, double area, const char *address, size_t floors, const char *owner)
    : Building(height, area, address), mFloors(floors) {
    mOwner = new char[strlen(owner) + 1];
    strcpy(mOwner, owner);
}

House::House(const House &other) : Building(other) {
    copy(other);
}

House &House::operator=(const House &other) {
    if (this == &other) {
        return *this;
    }
    Building::operator=(other);
    free();
    copy(other);
    return *this;
}

House::~House() {
    free();
}

double House::averageFloorHeight() const {
    double average = getHeight() / mFloors;
    return average;
}

ostream &operator<<(ostream &out, const House &h) {
    out << "======House Info======\n";
    out << "Owner: " << h.mOwner << '\n';
    out << "Floors: " << h.mFloors << '\n';
    out << "Address: " << h.mAddress << '\n';
    out << "Area: " << h.mArea << '\n';
    out << "Height: " << h.mHeight << '\n';
    return out;
}

istream &operator>>(istream &in, House &h) {
    cout << "======House Information======\n";
    in.get();

    cout << "Owner: ";
    char buff[1024];
    in.getline(buff, 1024);
    h.mOwner = new char[strlen(buff) + 1];
    strcpy(h.mOwner, buff);

    cout << "Floors: ";
    in >> h.mFloors;

    in.get();
    cout << "Address: ";
    char buffa[1024];
    in.getline(buffa, 1024);
    h.mAddress = new char[strlen(buffa) + 1];
    strcpy(h.mAddress, buffa);

    cout << "Area: ";
    in >> h.mArea;

    cout << "Height: ";
    in >> h.mHeight;

    return in;
}