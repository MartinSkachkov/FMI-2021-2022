#ifndef _BUILDING_H_
#define _BUILDING_H_
#include <fstream>

class Building {
protected:
    double mHeight;
    double mArea;
    char *mAddress;

    void copy(const Building &other);
    void free();

public:
    Building(double height, double area, const char *address);
    Building(const Building &other);
    Building &operator=(const Building &other);
    ~Building();

    // getters
    double getHeight() const { return mHeight; }
    double getArea() const { return mArea; }
    const char *getAddress() const { return mAddress; }

    friend std::ostream &operator<<(std::ostream &out, const Building &b);
    friend std::istream &operator>>(std::istream &in, Building &b);
};

#endif