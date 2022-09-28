#ifndef _HOUSE_H_
#define _HOUSE_H_
#include "Building.h"
#include <cstdlib>

class House : public Building {
private:
    size_t mFloors;
    char *mOwner;

    void copy(const House &other);
    void free();

public:
House();
    House(double height, double area, const char *address, size_t floors, const char *owner);
    House(const House &other);
    House &operator=(const House &other);
    ~House();

    double averageFloorHeight() const;

    friend std::ostream &operator<<(std::ostream &out, const House &h);
    friend std::istream &operator>>(std::istream &in, House &h);
};

#endif