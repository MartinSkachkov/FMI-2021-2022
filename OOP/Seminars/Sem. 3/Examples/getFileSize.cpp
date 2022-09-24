#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

size_t getFileSize(ifstream &in) {
    size_t currPos = in.tellg();
    in.seekg(0, ios::end); // move the get ptr to the end of the file
    size_t result = in.tellg();
    in.seekg(currPos);
    return result;
}

int main() {
    ifstream in("file.txt");

    if (!in.is_open()) {
        std::cout << "Error while opening the file!\n";
        return -1;
    }

    cout << getFileSize(in);

    in.close();
    return 0;
}