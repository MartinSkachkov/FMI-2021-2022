#ifndef ZOO_H
#define ZOO_H
#include <fstream>
#include "Animal.h"
using namespace std;

struct Zoo {
    char* mName;
    Animal* mAnimalList;
    unsigned int mAnimalNumber;
    unsigned int mAnimalMaxSize;

    void initialize();
    void deleteDynamic();
    void loadFromStream(ifstream& in);
    void writeToStream(ofstream& out);
};

#endif
