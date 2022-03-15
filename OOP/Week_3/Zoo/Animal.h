#endif
#ifndef ANIMAL_H
#define ANIMAL_H
#include <fstream>
using namespace std;

enum AnimalType {
    MAMMAL = 1,
    REPTILE,
    FISH,
    BIRD,
    AMPHIBIAN,
    IVERTEBRATES,
    INSECT
};

struct Animal {
    AnimalType mType;
    char* mName;
    int mAge;

    void initialize();
    void deleteDynamics();
    void loadFromStream(ifstream& in);
    void writeToStream(ofstream& out);
};

#endif
