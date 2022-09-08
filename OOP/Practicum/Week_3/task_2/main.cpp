#include "Date.h"
#include <iostream>

void textTest() {
    Date date;
    std::cout << "Input day:";
    std::cin >> date.mDay;

    date.mMonth = new char[5];
    std::cout << "Input month:";
    std::cin >> date.mMonth;

    std::cout << "Input year:";
    std::cin >> date.mYear;

    std::cout << "Input hours:";
    std::cin >> date.mTime.mHours;

    std::cout << "Input minutes:";
    std::cin >> date.mTime.mMinutes;

    std::ofstream outFile("date.txt");
    date.writeDate(outFile);

    outFile.close();

    std::ifstream inFile("date.txt");
    Date readDateVar;
    readDateVar.readDate(inFile);
    readDateVar.writeDate(std::cout);

    inFile.close();
}

int main() {
    textTest();

    Date date;
    date.getCurrentDate();
    date.writeDate(std::cout);

    return 0;
}