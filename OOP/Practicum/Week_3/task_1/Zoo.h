#ifndef __ZOO_H_
#define __ZOO_H_
#include "Animal.h"

struct Zoo {
    char *mName;
    Animal *animals;
    size_t mCurrSize;
    size_t mMaxCapacity;

    void initialize();
    void free();
    void loadFromStream(istream &in);
    void writeToStream(ostream &out) const;
    bool hasType(const Type &type) const;
};

#endif