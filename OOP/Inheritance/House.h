#ifndef __HOUSE_
#define __HOUSE_
#include "Building.h"

class House : public Building {
private:
	size_t mFloorsCount;
	size_t mAverageHight;
	char* mOwner;
public:
	//setters
	void setFloorsCount();
	void setOwner();
	void setAverageHight();

	//getters
	size_t getFloorsCount() const;
	const char* getOwner() const;
	size_t getAverageHeight() const;

	~House();

	friend ostream& operator<<(ostream& os, const House& house);
	friend istream& operator>>(istream& is, House& house);
};

#endif
