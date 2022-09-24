#include <fstream>
#include <iostream>
using namespace std;

void replaceInFile(const char ch1, const char ch2, fstream &input) {
    while (!input.eof()) {
        char currSym = input.get();
        if (currSym != ch1) {
            continue;
        } else {
            input.seekp(-1, ios::cur);
            input.put(ch2);
            input.flush();
        }
    }
}

int main() {
    fstream input("file.txt");

    if (!input.is_open()) {
        cout << "Error while opening the file!" << std::endl;
        return -1;
    }

    replaceInFile('a', 'X', input);

    input.close();
    return 0;
}