#include <iostream>
using namespace std;
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

void printAreas(Shape** shapes, const size_t shapesCount) {
	for (size_t i = 0; i < shapesCount; i++){
		cout << shapes[i]->getArea() << endl;
	}
}

void printPers(Shape** shapes, const size_t shapesCount) {
	for (size_t i = 0; i < shapesCount; i++){
		cout << shapes[i]->getPerimeter();
	}
}

void freeCollection(Shape** shapes, const size_t shapesCount) {
	for (int i = 0; i < shapesCount; i++) {
		delete[] shapes[i];
	}
	delete[] shapes;
}

int main() {
	Shape** arr = new Shape * [4];

	arr[0] = new Rectangle(3, 4, 6, 8);
	arr[1] = new Circle(3, 3, 4);
	arr[2] = new Circle(1, 4, 5);
	arr[3] = new Triangle(1, 1, 2, 2, 3, 3);

	printAreas(arr, 4);
	printPers(arr, 4);
	freeCollection(arr, 4);
}
