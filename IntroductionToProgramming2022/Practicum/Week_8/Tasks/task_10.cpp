#include <iostream>
using namespace std;

void initialize(int* array, const unsigned int size) {
    cout << "Initialize array: ";
    for (size_t i = 0; i < size; i++) {
        cin >> array[i];
    }
}

int mostCommonElement(int* array, const unsigned int size) {
    int counter = 0, maxCounter = 0, mostCommonEl = 0;
    for (size_t i = 0; i < size; i++) {
        counter = 0;
        for (size_t j = 0; j < size; j++) {
            if (array[i] == array[j]) {
                counter++;
            }
        }
        if (counter > maxCounter) {
            maxCounter = counter;
            mostCommonEl = array[i];
        }
    }
    return mostCommonEl;
}

int countCommonElement(int* array, const unsigned int size) {
    int counter = 0, maxCounter = 0;
    for (size_t i = 0; i < size; i++) {
        counter = 0;
        for (size_t j = 0; j < size; j++) {
            if (array[i] == array[j]) {
                counter++;
            }
        }
        if (counter > maxCounter) {
            maxCounter = counter;
        }
    }
    return maxCounter;
}

int main() {
    unsigned int size;
    cout << "size: ";
    cin >> size;
    int* array = new int[size];

    initialize(array, size);
    cout << "Most common element " << mostCommonElement(array, size)
         << " is repeated " << countCommonElement(array, size) << " times";

    delete[] array;
    return 0;
}