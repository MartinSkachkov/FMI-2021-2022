#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_
#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(int x1, int y1, int x2, int y2);
	virtual double getArea() const override;
	virtual double getPerimeter() const override;
};

#endif
