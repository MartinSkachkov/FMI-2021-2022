#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream readFile("test1.txt"); // create an object of type input stream and connect it to the file test.txt
    /*alternatively:
    ifstream readFile;
    readfile.open("test.txt");*/

    if (!readFile.is_open()) { // check if file was opened
        cout << "Couldn't open the file!\n";
        return -1;
    } else {
        cout << "File was successfully opened!\n";
    }

    char buff[1024];
    double dNum;
    int iNum;

    readFile >> buff >> dNum >> iNum; // initializing the variables from the values in the file
    cout << buff << '\n'
         << dNum << '\n'
         << iNum << '\n';

    readFile.close();
    return 0;
}