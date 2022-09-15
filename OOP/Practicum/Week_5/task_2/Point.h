#ifndef _POINT_H_
#define _POINT_H_

class Point {
private:
    double mX;
    double mY;

public:
    Point();
    double getX() const;
    double getY() const;
};

#endif