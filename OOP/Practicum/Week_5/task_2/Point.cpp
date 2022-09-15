#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() {
    cout << "x: ";
    cin >> mX;
    cout << "y: ";
    cin >> mY;
}

double Point::getX() const { return mX; }

double Point::getY() const { return mY; }