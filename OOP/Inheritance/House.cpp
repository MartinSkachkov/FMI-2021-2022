#include "House.h"

//setters
void House::setFloorsCount() {
	cout << "Number of floors: ";
	cin >> mFloorsCount;
}

void House::setOwner() {
	char buffer[MAX_SIZE];
	cout << "Owner: ";
	cin >> buffer;
	char* mOwner = new char[strlen(buffer) + 1];
	strcpy_s(mOwner, strlen(buffer) + 1, buffer);
}

void House::setAverageHight() {
	this->mAverageHight = getBuildingHeight() / mFloorsCount;
}

//getters
size_t House::getFloorsCount() const {
	return mFloorsCount;
}

const char* House::getOwner() const {
	return mOwner;
}

size_t House::getAverageHeight() const {
	return mAverageHight;
}

ostream& operator<<(ostream& os, const House& house) {
	os << "====== INFO ======\n";
	os << "Building height: " << house.getBuildingHeight() << endl
		<< "Area(m^2): " << house.getArea() << endl
		<< "Address: ";
	os << house.mAddress << endl; // ???? getAddress()
	os << "Number of floors: " << house.getFloorsCount() << endl;
	os << "Owner: " << house.mOwner << endl;
	return os;
}

istream& operator>>(istream& is, House& house) {
	cout << "=== ENTER HOUSE INFO ===\n";
	cout << "Building height: ";
	is >> house.mBuildingHeight;

	cout << "Area: ";
	is >> house.mArea;

	cout << "Address: ";
	char bufferAddress[MAX_SIZE];
	cin.ignore();
	cin.getline(bufferAddress, MAX_SIZE);
	char* mAddress = new char[strlen(bufferAddress) + 1];
	strcpy_s(mAddress, strlen(bufferAddress) + 1, bufferAddress);

	cout << "Number of floors: ";
	is >> house.mFloorsCount;

	cout << "Owner: ";
	char bufferOwner[MAX_SIZE];
	cin.getline(bufferOwner, MAX_SIZE);
	char* mOwner = new char[strlen(bufferOwner) + 1];
	strcpy_s(mOwner, strlen(bufferOwner) + 1, bufferOwner);
	return is;
}

House::~House() {
	delete[] mOwner;
}