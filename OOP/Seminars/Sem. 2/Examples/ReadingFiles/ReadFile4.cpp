#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream readFile;
    readFile.open("test4.txt");

    if (!readFile.is_open()) {
        cout << "Couldn't open the file\n";
        return -1;
    }

    char c;
    while (!readFile.eof()) {
        readFile.get(c);
        cout << c;
    }

    readFile.close();
    return 0;
}