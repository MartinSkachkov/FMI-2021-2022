#ifndef __SHAPE_H_
#define __SHAPE_H_
#include <iostream>
using namespace std;

class Shape { //abstract class
protected: //derived classes hace access to the point struct
	struct Point {
		int mX;
		int mY;
		Point(int x = 0, int y = 0) : mX(x), mY(y) {}
		double getDist(const Point& other) const {
			int dx = mX - other.mX;
			int dy = mY - other.mY;
			return sqrt(dx * dx + dy * dy);
		}
	};
	const Point& getPointIndex(size_t index) const;
private:
	Point* mPoints; //array of points
	size_t mPointsCount; //size of the array

	void copy(const Shape& other);
	void free();
public:
	Shape(size_t pointsCount);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();

	void setPoint(size_t pointIndex, int x, int y);
	virtual double getArea() const = 0; //pure virtual - can't create objects and it is virtual because we can't write what is the area of just a SHAPE, they will be overriden
	virtual double getPerimeter() const = 0; //pure virtual
};

#endif
