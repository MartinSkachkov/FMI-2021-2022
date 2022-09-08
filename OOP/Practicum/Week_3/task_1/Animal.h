#ifndef __ANIMAL_H_
#define __ANIMAL_H_
#include <fstream>
using namespace std;

enum Type {
    mammal = 1,
    reptile,
    fish,
    bird,
    amphibian,
    ivertebrates,
    insect
};

struct Animal {
    Type mAnimalType;
    char *mName;
    size_t mAge;

    void initialize();
    void free();
    void loadFromStream(istream &in);
    void writeToStream(ostream &out) const;
};

#endif