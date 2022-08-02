#include <cstring>
#include <iostream>
using namespace std;

int index = 0;  // bad practice but....

// replacing the substring int the original text with what we want
void replaceFunc(char* text, const char* replace) {
    if (text[index] != 0) {
        size_t replaceIterator = 0;
        while (text[index + replaceIterator] != 0 &&
               replace[replaceIterator] != 0 &&
               replaceIterator != strlen(replace)) {
            text[index + replaceIterator] = replace[replaceIterator];
            replaceIterator++;
        }
    }
}

// checking if the substring is contained in the original text
bool hasValidSubstring(const char* text, const char* find) {
    size_t textIterator = 0;
    bool hasValidSubstring = false;  // only change from task_7
    while (text[textIterator] != 0) {
        if (text[textIterator] == find[0]) {
            size_t k = 0;
            while (text[textIterator + k] != 0 && find[k] != 0 &&
                   text[textIterator + k] == find[k]) {
                k++;
            }
            if (k == strlen(find)) {
                index = textIterator;  // saving the index from which we start
                                       // the raplacing
                hasValidSubstring = true;  // only change from task_7, we don't
                                           // break, we continue checking
            }
        }
        textIterator++;
    }
    return hasValidSubstring;
}

int main() {
    size_t textSize;
    cout << "text size: ";
    cin >> textSize;

    char* text = new char[textSize + 1];
    cout << "text: ";
    cin.get();
    cin.getline(text, textSize + 1);

    size_t findSize;
    cout << "find size: ";
    cin >> findSize;

    char* find = new char[findSize + 1];
    cout << "find what: ";
    cin.get();
    cin.getline(find, findSize + 1);

    size_t replaceSize;
    cout << "replace size: ";
    cin >> replaceSize;

    char* replace = new char[replaceSize + 1];
    cout << "replace with: ";
    cin.get();
    cin.getline(replace, replaceSize + 1);

    try {
        if (textSize < findSize || findSize != replaceSize) {
            throw "invalid size perimeters";
        }
    } catch (const char* err) {
        cout << err << endl;
        return -1;
    }

    if (hasValidSubstring(text, find)) {
        replaceFunc(text, replace);
    }

    cout << "result: " << text;

    delete[] text;
    delete[] replace;
    delete[] find;
    return 0;
}