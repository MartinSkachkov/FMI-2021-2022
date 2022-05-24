#ifndef __Building_
#define __Building_
#include <iostream>
#include <fstream>
#define MAX_SIZE 1024
using namespace std;

class Building {
protected:
	size_t mBuildingHeight;
	size_t mArea;
	char* mAddress;
public:
	//setters
	void setBuildingHeight();
	void setArea();
	void setAddress();

	//getters
	size_t getBuildingHeight() const;
	size_t getArea() const;
	const char* getAddress() const;

	~Building();

	friend istream& operator>>(istream& is, Building& building);
};

#endif
