#include "Developer.h"
#include <cstring>
#include <iostream>
#include <time.h>
#define MAX_SIZE 15
using namespace std;

void generateId(size_t &mId) {
    srand(time(0));
    size_t randomNum = rand() % 9999 + 1000;
    mId = randomNum;
}

void printPositionList() {
    cout << "===Position_List===\n";
    cout << "1) JUNIOR_DEV\n"
         << "2) DEV\n"
         << "3) SENIOR_DEV\n"
         << "4) QA\n"
         << "5) MANAGER\n";
}

void Developer::init() {
    generateId(mId);

    char firstName[MAX_SIZE] = {0};
    cout << "First Name: ";
    cin.getline(firstName, MAX_SIZE);
    mFirstName = new char[strlen(firstName) + 1];
    strcpy_s(mFirstName, strlen(firstName) + 1, firstName);

    char lastName[MAX_SIZE] = {0};
    cout << "Second Name: ";
    cin.getline(lastName, MAX_SIZE);
    mLastName = new char[strlen(lastName) + 1];
    strcpy_s(mLastName, strlen(lastName) + 1, lastName);

    printPositionList();
    cout << "Position: ";
    size_t choice;
    cin >> choice;
    mPosition = (Position)choice;
}

void Developer::free() {
    delete[] mFirstName;
    delete[] mLastName;
}

void Developer::writeToFile(ostream &out) const {
    out << mId << '\n';
    out << strlen(mFirstName) << ' ' << mFirstName << '\n';
    out << strlen(mLastName) << ' ' << mLastName << '\n';
    out << mPosition;
}

void Developer::readFromFile(ifstream &in) {
    in >> mId;

    size_t firstNameLen = 0;
    in >> firstNameLen;
    mFirstName = new char[firstNameLen + 1];
    in >> mFirstName;

    size_t lastNameLen = 0;
    in >> lastNameLen;
    mLastName = new char[lastNameLen + 1];
    in >> mLastName;

    size_t pos;
    in >> pos;
    mPosition = (Position)pos;
}

void Developer::print() const {
    cout << "------------- Developer -------------\n";
    writeToFile(cout); // wants the func arg to be ostream not ofstream
    cout << "-------------------------------------\n";
}