#include <cstring>
#include <iostream>
#define EXTRACT_SIZE 100
using namespace std;

size_t sourceIterator;

char* extractWord(char* source, size_t& wordLen) {
    char* extractor = new char[EXTRACT_SIZE];
    size_t sourceIterator = 0, extractorIterator = 0;
    while (source[sourceIterator] != 0) {
        if (source[sourceIterator] != ' ') {
            extractor[extractorIterator++] = source[sourceIterator];
        }
        if (source[sourceIterator] == ' ') {
            sourceIterator++;
            break;
        }
        sourceIterator++;
    }
    wordLen = extractorIterator;
    extractor[extractorIterator] = 0;
    return extractor;
}

char** split(char* source, char delimiter, size_t& size) {
    // we find the number of words
    size_t words = 1;
    for (size_t i = 0; i < size; i++) {
        if (source[i] == delimiter) {
            words++;
        }
    }
    size = words;

    // alloc mem for n number of words
    char** result = new char*[words];
    size_t wordLen = 0;

    char* extractor;

    for (size_t i = 0; i < words; i++) {
        extractor = extractWord(source, wordLen);
        result[i] = new char[wordLen + 1];
        strcpy_s(result[i], wordLen + 1, extractor);
    }
    delete[] extractor;
    return result;
}

int main() {
    size_t length;
    cout << "length: ";
    cin >> length;
    char* source = new char[length + 1];

    cout << "string: ";
    cin.get();
    cin.getline(source, length + 1);

    // passing length by reference cuz we want to change it
    char** result = split(source, ' ', length);
    for (size_t i = 0; i < length; i++) {
        cout << result[i] << "\n";
    }

    for (size_t i = 0; i < length; i++) {
        delete[] result[length];
    }
    delete[] result;
    delete[] source;

    return 0;
}