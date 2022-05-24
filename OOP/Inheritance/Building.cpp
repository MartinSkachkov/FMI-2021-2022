#include "Building.h"

//setters
void Building::setBuildingHeight() {
	cout << "Building height: ";
	cin >> mBuildingHeight;
}

void Building::setArea() {
	cout << "Area: ";
	cin >> mArea;
}

void Building::setAddress() {
	char buffer[MAX_SIZE];
	cout << "Address: ";
	cin >> buffer;
	char* mAddress = new char[strlen(buffer) + 1];
	strcpy_s(mAddress, strlen(buffer) + 1, buffer);
}

//getters
size_t Building::getBuildingHeight() const{
	return mBuildingHeight;
}

size_t Building::getArea() const{
	return mArea;
}

const char* Building::getAddress() const {
	return mAddress;
}

Building::~Building() {
	delete[] mAddress;
}

istream& operator>>(istream& is, Building& building) {
	is >> building.mBuildingHeight >> building.mArea >> building.mAddress;
	return is;
}