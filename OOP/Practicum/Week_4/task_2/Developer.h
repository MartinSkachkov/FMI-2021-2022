#ifndef _DEVELOPER_H_
#define _DEVELOPER_H_
#include "Position.h"
#include <cstddef>
#include <fstream>

class Developer {
private:
    size_t mId;
    char *mFirstName;
    char *mLastName;
    Position mPosition;

public:
    void init();
    void free();
    void writeToFile(std::ostream &out) const;
    void readFromFile(std::ifstream &in);
    void print() const;
};

#endif