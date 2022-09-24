#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
bool findSubstring(const string &readWord, const string &searchWord) {
    size_t findIndex = readWord.find(searchWord); // find method returns the index of the first match (find searchWord in readWord)
    if (findIndex == string::npos) {              // this means that we just care if the searched word is there or not(we don't care about anything else)
        return false;
    } else {
        return true;
    }
}

int main() {
    string searchWord;
    cout << "Find: ";
    cin >> searchWord;

    ifstream readFile("romeoandjuliet.txt");

    if (!readFile.is_open()) {
        cout << "Couldn't open the file";
        return -1;
    }

    string readWord;
    size_t matchCount = 0;
    size_t wordCount = 0;
    while (!readFile.eof()) {
        readFile >> readWord;                      // stops at whitespace
        if (findSubstring(readWord, searchWord)) { // if the two words match or the one is a substring of another
            matchCount++;
            cout << readWord << ' ';
        }
        wordCount++;
    }

    cout << wordCount << " were searched...\n"
         << "The substring " << searchWord << " was found " << matchCount << " times\n";
    readFile.close();
    return 0;
}
