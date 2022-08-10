#include <cstring>
#include <iostream>
#define EXTRACT_SIZE 100
using namespace std;

bool isLetterNDigit(char symbol) {
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'B') ||
        (symbol >= '0' && symbol <= '9')) {
        return true;
    }
    return false;
}

void addWord(char**& result, char* source, size_t startIndex, size_t endIndex,
             size_t& size) {
    char** newResult = new char*[size + 1];  // plus one because we add a word
    // copy the old words to the newResult
    for (size_t i = 0; i < size; i++) {
        newResult[i] = new char[strlen(result[i]) + 1];
        strcpy_s(newResult[i], strlen(result[i]) + 1, result[i]);
        delete[] result[i];  // delete old words
    }
    delete[] result;  // delete whole arr of old words

    // plus 1 because for \0
    newResult[size] = new char[endIndex - startIndex + 1];
    size_t ctr = 0;
    for (size_t i = startIndex; i < endIndex; i++) {
        newResult[size][ctr++] = source[i];
    }

    newResult[size][ctr] = 0;  // adding the \0
    size++;
    result = newResult;  // make it point to the array with old and new words
}

char** split(char* source, char delimiter, size_t& size) {
    size_t left = 0;
    size_t right = strlen(source) - 1;

    // trim the empty spaces from the fron and end
    while (source[left] == delimiter) {
        left++;
    }
    while (source[right] == delimiter) {
        right--;
    }

    char** result = nullptr;
    size_t startIndex = left;

    for (size_t i = left; i < right; i++) {
        if (source[i] == delimiter) {
            addWord(result, source, startIndex, i, size);
            startIndex = i + 1;
        }
    }

    // if we have only one word as input or we have to add the last word because
    // the for loop won't add it
    if (size != 0 || (left == 0 && right == strlen(source) - 1)) {
        addWord(result, source, startIndex, right + 1, size);
    }
    return result;
}

size_t minWordIndex(char** splitted, size_t size) {
    size_t minWordIndex = 0;
    int minWord = INT_MAX;
    for (size_t i = 0; i < size; i++) {
        if (isLetterNDigit(*(splitted[i])) && (*(splitted[i]) < minWord)) {
            minWordIndex = i;
            minWord = *(splitted[i]);
        }
    }
    return minWordIndex;
}

int main() {
    size_t length;
    cout << "length: ";
    cin >> length;
    char* source = new char[length + 1];

    cout << "string: ";
    cin.get();
    cin.getline(source, length + 1);

    cout << "delimeter: ";
    char delimeter;
    cin.get(delimeter);

    // passing splitSize by reference cuz we want to change it
    size_t splitSize = 0;
    char** result = split(source, delimeter, splitSize);

    /*if (result != nullptr) {
            for (size_t i = 0; i < length; i++) {
                    cout << result[i] << "\n";
            }
    }*/

    cout << "min word:\n";
    for (size_t i = minWordIndex(result, splitSize); i < splitSize; i++) {
        cout << result[i] << ' ';
    }

    for (size_t i = 0; i < splitSize; i++) {
        delete[] result[i];
    }
    delete[] result;
    delete[] source;

    return 0;
}