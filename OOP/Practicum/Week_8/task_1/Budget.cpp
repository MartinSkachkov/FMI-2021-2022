#include "Budget.h"
#include <iomanip>
#include <iostream>
using namespace std;

double Budget::mUniBudget = 0.0;

Budget::Budget(double facultyBudget) : mFacultyBudget(facultyBudget) {
    mUniBudget += mFacultyBudget;
}

void Budget::addToBudget(double money) {
    mFacultyBudget += money;
    mUniBudget += mFacultyBudget;
}

void Budget::addFromAdmin(double money) {
    mUniBudget += money;
}

Budget &Budget::operator+=(double money) {
    mFacultyBudget += money;
    return *this;
}

Budget &Budget::operator-=(double money) {
    mFacultyBudget -= money;
    return *this;
}

bool Budget::operator==(const Budget &rhs) const {
    return mFacultyBudget == rhs.mFacultyBudget;
}

bool Budget::operator!=(const Budget &rhs) const {
    return (*this == rhs);
}

ostream &operator<<(ostream &out, const Budget &b) {
    out << "Fuculty budget: " << b.mFacultyBudget;
    return out;
}

istream &operator>>(istream &in, Budget &b) {
    cout << "Fuculty budget: ";
    in >> b.mFacultyBudget;
    return in;
}

/*const Budget operator+(const Budget &lhs, const Budget &rhs) {
    Budget updated(lhs);
    updated += rhs;
    return updated;
}

const Budget operator-(const Budget &lhs, const Budget &rhs) {
    Budget updated(lhs);
    updated -= rhs;
    return updated;
}*/