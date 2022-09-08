#include "Date.h"
#define MAX_SIZE 15
#include <cstring>
#include <iostream>

int convertToInt(char *temp) {
    int num = 0;
    for (size_t i = 0; i < 2; i++) {
        num += (temp[i] - '0');
        num *= 10;
    }
    num /= 10;
    return num;
}

void Date::readDate(ifstream &in) {
    // dd MMM YYYY, hh:mm
    in >> mDay;

    char buff[MAX_SIZE] = {0};
    cin.get(buff, MAX_SIZE, ' ');
    strcpy(mMonth, buff);

    in >> mYear;
    in.get(); // for ','
    in.get(); // for ' '

    char temp[2];
    in.get(temp[0]);
    in.get(temp[1]);
    mTime.mHours = convertToInt(temp);

    in.get(); // for ':'

    in.get(temp[0]);
    in.get(temp[1]);
    mTime.mMinutes = convertToInt(temp);
}

void Date::writeDate(ofstream &out) {
    // dd MMM YYYY, hh:mm
    out << mDay << ' ' << mMonth << ' ' << mYear << ', ' << mTime.mHours << ':' << mTime.mMinutes;
}

void Date::getCurrentDate() {
    time_t currentTime;
    tm *currentTimeStruct = new tm;
    time(&currentTime);
    localtime_r(&currentTime, currentTimeStruct);

    this->mDay = currentTimeStruct->tm_mday;

    switch (currentTimeStruct->tm_mon) {
    case 0:
        this->mMonth = (char *)"Jan";
        break;
    case 1:
        this->mMonth = (char *)"Feb";
        break;
    case 2:
        this->mMonth = (char *)"Mar";
        break;
    case 3:
        this->mMonth = (char *)"Apr";
        break;
    case 4:
        this->mMonth = (char *)"Mai";
        break;
    case 5:
        this->mMonth = (char *)"Jun";
        break;
    case 6:
        this->mMonth = (char *)"Jul";
        break;
    case 7:
        this->mMonth = (char *)"Aug";
        break;
    case 8:
        this->mMonth = (char *)"Sep";
        break;
    case 9:
        this->mMonth = (char *)"Oct";
        break;
    case 10:
        this->mMonth = (char *)"Nov";
        break;
    case 11:
        this->mMonth = (char *)"Dec";
        break;

    default:
        this->mMonth = (char *)"N/A";
    }

    this->mYear = currentTimeStruct->tm_year + 1900;
    this->mTime.mHours = currentTimeStruct->tm_hour;
    this->mTime.mMinutes = currentTimeStruct->tm_min;
}

void Date::free() {
    delete[] mMonth;
}