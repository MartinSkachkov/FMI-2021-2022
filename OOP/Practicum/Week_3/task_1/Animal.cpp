#include "Animal.h"
#include <cstring>
#include <iostream>
#define MAX_LEN 100

void Animal::initialize() {
    cout << "Animal Type:\n"
         << "1) mammal\n"
         << "2) reptile\n"
         << "3) fish\n"
         << "4) bird\n"
         << "5) amphibian\n"
         << "6) ivertebrates\n"
         << "7) insect\n";

    size_t choice;
    cout << "Choice: ";
    cin >> choice;

    if (choice < 1 || choice > 7) {
        throw "Not supported animal type!";
    }

    mAnimalType = (Type)choice;

    cout << "Name: ";
    char name[MAX_LEN] = {0};
    cin.ignore();
    cin.getline(name, MAX_LEN);
    mName = new char[strlen(name) + 1];
    strcpy(mName, name);

    cout << "Age: ";
    cin >> mAge;
}

void Animal::free() {
    delete[] mName;
}

void Animal::loadFromStream(istream &in) {
    // we load the information from a file and initialize the members of the struct with the value from the file
    size_t type;
    in >> type;

    if (type < 1 || type > 7) {
        throw "Not supported animal type!";
    }

    mAnimalType = (Type)type;

    size_t nameLen;
    in >> nameLen;
    mName = new char[nameLen + 1];

    char name[MAX_LEN];
    cin.ignore();
    cin.getline(name, nameLen + 1);
    strcpy(mName, name);

    in >> mAge;
}

void Animal::writeToStream(ostream &out) const {
    // we write the information to the file
    out << mAnimalType << '\n';
    out << strlen(mName) << ' ' << mName << '\n';
    out << mAge << '\n';
}