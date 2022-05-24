#ifndef __CIRCLE_H_
#define __CIRCLE_H_
#include "Shape.h"

class Circle : public Shape {
private:
	double mRadius;
	double PI = 3.14;
public:
	Circle(int x, int y, double radius);
	virtual double getArea() const override;
	virtual double getPerimeter() const override;
};

#endif
