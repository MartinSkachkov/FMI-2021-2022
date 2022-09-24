#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream write("Output.txt"); // if the file doesn't exist it will be automatically created
    // default set is trunc (erase the old content and write the new one, ios::app removes it);
    if (!write.is_open()) {
        cout << "Error!\n";
        return 1;
    }

    size_t symbolsToEnter = 0;
    cout << "Symbols count: ";
    cin >> symbolsToEnter;

    char *buff = new char[symbolsToEnter + 1];
    cin.ignore();
    cin.getline(buff, symbolsToEnter + 1);

    write << buff;

    write.close();
    return 0;
}