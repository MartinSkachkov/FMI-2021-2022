#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : Shape(4) {
	setPoint(0, x1, y1);
	setPoint(1, x1, y2);
	setPoint(2, x2, y1);
	setPoint(3, x2, y2);
}

double Rectangle::getArea()const {
	Shape::Point p0 = getPointIndex(0);
	Shape::Point p1 = getPointIndex(2);
	Shape::Point p3 = getPointIndex(3);

	return p0.getDist(p1) * p1.getDist(p3);
}

double Rectangle::getPerimeter()const {
	Shape::Point p0 = getPointIndex(0);
	Shape::Point p1 = getPointIndex(2);
	Shape::Point p3 = getPointIndex(3);

	return 2 * (p0.getDist(p1)) + 2 * (p1.getDist(p3));
}