#include "Shape.h"

void Shape::copy(const Shape& other) {
	mPoints = new Point[other.mPointsCount];
	for (size_t i = 0; i < other.mPointsCount; i++) {
		mPoints[i] = other.mPoints[i]; //obj = other obj
	}
	mPointsCount = other.mPointsCount;
}

void Shape::free() {
	delete[] mPoints;
}

Shape::Shape(size_t pointsCount) : mPointsCount(pointsCount) {
	mPoints = new Point[pointsCount]; //constr of Point (0,0)
}

Shape::Shape(const Shape& other) {
	copy(other);
}

Shape& Shape::operator=(const Shape& other) {
	if (this == &other) {
		return *this;
	}
	free();
	copy(other);
	return *this;
}

Shape::~Shape() {
	free();
}

void Shape::setPoint(size_t pointIndex, int x, int y) {
	if (pointIndex >= mPointsCount) {
		throw exception("Invalid point index!");
	}
	mPoints[pointIndex] = Point(x, y);
}

const Shape::Point& Shape::getPointIndex(size_t index)const {
	if (index >= mPointsCount) {
		throw exception("Invalid point");
	}
	return mPoints[index];
}