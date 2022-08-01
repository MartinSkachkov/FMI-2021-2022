#include <iostream>
using namespace std;

size_t strlen(const char* string) {
    size_t length = 0;
    while (*string != 0) {
        string++;
        length++;
    }
    return length;
}

size_t indexMatch(const char* string, const char symbol) {
    size_t length = strlen(string);
    for (size_t i = 0; i < length; i++) {
        if (string[i] == symbol) {
            return i + 1;
        }
    }
    return -1;
}  // string is const because we don't want to
   // change the elements in the array

int main() {
    size_t size;
    cout << "size: ";
    cin >> size;
    char* string = new char[size + 1];  //\0

    cin.get();
    cout << "enter string: ";
    cin.getline(string, size + 1);  //\0
    char symbol;
    cout << "symbol: ";
    cin >> symbol;

    cout << "first match on position: " << indexMatch(string, symbol) << endl;

    delete[] string;
    return 0;
}