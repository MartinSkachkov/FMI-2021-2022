#ifndef __DATE_H_
#define __DATE_H_
#include "Time.h"
#include <fstream>
using namespace std;

struct Date {
    size_t mYear;
    char *mMonth;
    size_t mDay;
    Time mTime;

    void readDate(ifstream &in);
    void writeDate(ofstream &out);
    void getCurrentDate();
    void free();
};

#endif