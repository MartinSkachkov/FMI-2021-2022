#include "Zoo.h"
#include <cstring>
#include <iostream>
#define MAX_LEN 100

void Zoo::initialize() {
    cout << "Zoo name: ";
    char name[MAX_LEN];
    // cin.ignore();
    cin.getline(name, MAX_LEN);
    mName = new char[strlen(name) + 1];
    strcpy(mName, name);

    cout << "Number of animals in the Zoo: ";
    cin >> mCurrSize;
    mMaxCapacity = mCurrSize;

    animals = new (nothrow) Animal[mCurrSize];
    if (!animals) {
        throw "Couldn't allocate memory!";
    }

    cout << "Identify the animals:\n";
    for (size_t i = 0; i < mCurrSize; i++) {
        animals[i].initialize();
    }
}

void Zoo::free() {
    delete[] mName;
    for (size_t i = 0; i < mCurrSize; i++) {
        animals[i].free();
    }
    delete[] animals;
}

void Zoo::loadFromStream(istream &in) {
    size_t nameLen;
    in >> nameLen;

    mName = new char[nameLen + 1];
    char name[MAX_LEN];
    cin.ignore();
    cin.getline(name, nameLen + 1);
    strcpy(mName, name);

    in >> mMaxCapacity >> mCurrSize;

    animals = new Animal[mMaxCapacity];
    for (size_t i = 0; i < mCurrSize; i++) {
        animals[i].loadFromStream(in);
    }
}

void Zoo::writeToStream(ostream &out) const {
    out << strlen(mName) << ' ' << mName;
    out << mMaxCapacity << ' ' << mCurrSize;
    for (size_t i = 0; i < mCurrSize; i++) {
        animals[i].writeToStream(out);
    }
}

bool Zoo::hasType(const Type &type) const {
    for (size_t i = 0; i < mCurrSize; i++) {
        if (animals[i].mAnimalType == type) {
            return true;
        }
    }
    return false;
}