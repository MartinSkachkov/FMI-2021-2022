#include "Developer.h"
#include <iostream>

int main() {
    Developer dev;

    try {
        dev.init();
    } catch (const char *e) {
        std::cerr << e << '\n';
        return 1;
    }

    std::ofstream outFile("developers.txt", std::ios::app);
    dev.writeToFile(outFile);

    outFile.close();

    dev.free();

    Developer dev1;
    std::ifstream inFile("developers.txt");
    try {
        dev1.readFromFile(inFile);
    } catch (const char *e) {
        std::cerr << e << '\n';
        return 1;
    }
    dev1.print();

    inFile.close();

    dev1.free();
    return 0;
}