#include <iostream>
using namespace std;

// size_t strlen(const char* str){
//     size_t length = 0;
//     while(*str!=0){
//         length++;
//         str++;
//     }
//     return length;
// }

const char* swapLetters(char* str1, size_t size1, char* str2, size_t size2) {
    if (size1 > size2) {
        for (size_t i = 0; i < 3; i++) {
            str1[i] = str2[i];
        }
        return str1;
    } else if (size1 < size2) {
        for (size_t i = 0; i < 3; i++) {
            str2[i] = str1[i];
        }
        return str2;
    } else {
        return "euqal length";  // requires const char*
    }
}

int main() {
    size_t size1, size2;
    cout << "size1: ";
    cin >> size1;
    cout << "size2: ";
    cin >> size2;

    char* str1 = new char[size1 + 1];
    char* str2 = new char[size2 + 1];

    cin.get();
    cout << "str1: ";
    cin.getline(str1, size1 + 1);
    cout << "str2: ";
    cin.getline(str2, size2 + 1);

    size_t maxSize = size1 > size2 ? size1 : size2;

    cout << maxSize << ' ' << swapLetters(str1, size1, str2, size2);

    delete[] str1;
    delete[] str2;
    return 0;
}