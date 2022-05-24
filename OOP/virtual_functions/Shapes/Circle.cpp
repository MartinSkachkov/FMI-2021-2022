#include "Circle.h"

Circle::Circle(int x, int y, double radius) : Shape(1), mRadius(radius) {
	setPoint(0, x, y);
}

double Circle::getArea()const {
	return PI * mRadius * mRadius;
}

double Circle::getPerimeter() const {
	return 2 * PI * mRadius;
}