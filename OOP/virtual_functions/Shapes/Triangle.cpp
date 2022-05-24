#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3) { //call the constr of shape and create a three point arr
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}

double Triangle::getArea() const {
	Shape::Point p1 = getPointIndex(0);
	Shape::Point p2 = getPointIndex(1);
	Shape::Point p3 = getPointIndex(2);

	return abs(p1.mX * p2.mY + p2.mX * p3.mY + p3.mX * p1.mY - p1.mY * p2.mX - p2.mY * p3.mX - p3.mY * p1.mX) / 2.00;
}

double Triangle::getPerimeter() const {
	Shape::Point p1 = getPointIndex(0);
	Shape::Point p2 = getPointIndex(1);
	Shape::Point p3 = getPointIndex(2);

	return p1.getDist(p2) + p2.getDist(p3) + p3.getDist(p1);
}