#include <iostream>
#define MAX_SIZE 100
using namespace std;

size_t strlen(const char* string) {
    size_t length = 0;
    while (*string != 0) {
        length++;
        string++;
    }
    return length;
}

int main() {
    char string[MAX_SIZE];
    cin.getline(string, MAX_SIZE);
    cout << "Length: " << strlen(string);
    return 0;
}