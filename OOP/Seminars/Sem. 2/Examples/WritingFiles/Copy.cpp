#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream read("Output.txt");
    ofstream write("Copy.txt");

    if (!read.is_open() || !write.is_open()) {
        cout << "Error!\n";
        return -1;
    }

    string line;
    while (!read.eof()) {
        getline(read, line);
        write << line << '\n';
    }

    /* one char at a time
    char c;
    while(!read.eof()){
        read.get(c);
        write.put(c);
    }*/

    read.close();
    write.close();
    return 0;
}