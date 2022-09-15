#ifndef _LINE_H_
#define _LINE_H_
#include "Point.h"

class Line {
private:
    Point mA;
    Point mB;

public:
    // the default constructor of Line will call the defaults of mA and mB
    //  bool isParallelWith(const Line& other) const;

    void printLinePoints() const;
};

#endif