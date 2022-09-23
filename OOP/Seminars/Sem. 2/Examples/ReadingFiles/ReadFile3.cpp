#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream readFile("C:\\Users\\Marto\\Desktop\\FMI\\FMI-2021-2022\\OOP\\Seminars\\Sem. 2\\Examples\\test3.txt");

    if (!readFile.is_open()) {
        cout << "Couldn't open the file!\n";
        return -1;
    }

    // reading line by line
    while (!readFile.eof()) {
        char buff[1024];
        readFile.getline(buff, 1024); // reads untill meeting a '\n' character (end of the line)
        cout << buff;
    }

    readFile.close();
    return 0;
}