#include <iostream>
using namespace std;

size_t strlen(const char* str) {
    size_t len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

// copy data from source to destination
void strcpy(char* destination, const char* source) {
    size_t length = strlen(source);
    for (size_t i = 0; i <= length; i++) {
        destination[i] = source[i];
    }
}

int main() {
    size_t sourceSize, destinationSize;
    do {
        cout << "source size: ";
        cin >> sourceSize;
        cout << "destination size: ";
        cin >> destinationSize;
    } while (destinationSize < sourceSize);

    char* source = new char[sourceSize + 1];
    char* destination = new char[destinationSize + 1];

    cin.get();
    cout << "source: ";
    cin.getline(source, sourceSize + 1);

    strcpy(destination, source);
    cout << "copy: ";
    cout << destination;

    delete[] source;
    delete[] destination;
    return 0;
}