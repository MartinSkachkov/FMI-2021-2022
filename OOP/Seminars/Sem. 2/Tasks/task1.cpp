#include <fstream>
#include <iostream>
#define LEN 1024
using namespace std;

int main() {
    char filename[LEN];
    cout << "Insert the filename/paht: ";
    cin.getline(filename, LEN);

    ifstream readFile(filename);

    if (!readFile.is_open()) {
        cout << "Couldn't open the file!\n";
        return -1;
    }

    while (!readFile.eof()) {
        char buff[LEN];
        readFile.getline(buff, LEN);
        cout << buff;
    }

    readFile.close();
    return 0;
}