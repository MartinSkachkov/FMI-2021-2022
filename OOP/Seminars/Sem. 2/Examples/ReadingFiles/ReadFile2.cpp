#include <fstream>
#include <iostream>
#define NAME_LEN 100
using namespace std;

int main() {
    char filename[NAME_LEN];
    cout << "Filename: ";
    cin.getline(filename, NAME_LEN);

    ifstream readFile(filename); // C:\\Users\\Marto\\Desktop\\FMI\\FMI-2021-2022\\OOP\\Seminars\\Sem. 2\\Examples\\test2.txt

    if (!readFile.is_open()) {
        cout << "Couldn't open the file!\n";
        return -1;
    } else {
        cout << "File was successfully opened\n";
    }

    char buff[NAME_LEN];
    double dNum;
    int iNum;

    // reading by initializing each variable with a value from the file
    while (!readFile.eof()) {
        readFile >> buff >> iNum >> dNum;
        cout << buff << ' ' << iNum << ' ' << dNum << '\n';
    }

    readFile.close();
    return 0;
}