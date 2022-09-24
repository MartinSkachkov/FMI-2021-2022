#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

bool copy(ifstream &read, ostream &write) {
    size_t numeration = 0;
    while (!read.eof()) {
        char buff[1024];
        read.getline(buff, 1024);
        write << setw(5) << left << numeration << buff << endl;
        numeration++;
    }
    return true;
}

int main() {
    ifstream read("romeoandjuliet.txt");
    ofstream write("copy-of-poem.txt");

    if (!read.is_open() || !write.is_open()) {
        cout << "Error\n";
        return -1;
    }

    if (copy(read, write)) {
        cout << "Copied!";
    }

    return 0;
}