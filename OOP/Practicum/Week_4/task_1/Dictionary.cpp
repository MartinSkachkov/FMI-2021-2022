#include "Dictionary.h"
#include <cstring>
#include <iostream>
using namespace std;

void Dictionary::init(Pair *words, const int &size) {
    int index = 0;
    mSize = 0;

    do {
        add(words[index++]);
    } while (index < size && index < MAX_PAIR_SIZE);
}

void Dictionary::print() const {
    cout << "-------DICTIONARY-------\n";
    for (size_t i = 0; i < mSize; i++) {
        mWords[i].print();
        cout << '\n';
    }
}

bool Dictionary::add(const Pair &newPair) {
    if (mSize >= MAX_PAIR_SIZE) {
        return false;
    } else {
        mWords[mSize++] = newPair.copy();
        return true;
    }
}

bool Dictionary::remove(const char *word) {
    int index = -1;
    for (size_t i = 0; i < mSize; i++) {
        if (strcmp(mWords[i].getWord(), word) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return false;
    } else {
        for (size_t i = index; i < mSize - 1; i++) {
            swap(mWords[i], mWords[i + 1]);
        }
        mWords[mSize - 1].free();
        mSize--;
        return true;
    }
}

char *Dictionary::findMeaning(const char *word) const {
    char *result = nullptr;
    for (size_t i = 0; i < mSize; i++) {
        if (strcmp(mWords[i].getWord(), word) == 0) {
            result = new char[strlen(mWords[i].getMeaning()) + 1];
            strcpy(result, mWords[i].getMeaning());
            result[strlen(mWords[i].getMeaning())] = 0;
        }
    }
    return result;
}

char *Dictionary::findMeaningByIndex(const unsigned &index) const {
    char *result = nullptr;

    if (index >= mSize) {
        return nullptr;
    } else {
        result = new char[strlen(mWords[index].getMeaning()) + 1];
        strcpy(result, mWords[index].getMeaning());
        result[strlen(mWords[index].getMeaning())] = 0;
    }
    return result;
}

void Dictionary::sort() {
    for (size_t i = 0; i < mSize - 1; i++) {
        for (size_t j = 0; j < mSize - 1 - i; j++) {
            if (strcmp(mWords[j].getWord(), mWords[j + 1].getWord()) > 0) {
                swap(mWords[j], mWords[j + 1]);
            }
        }
    }
}

void Dictionary::free() {
    for (size_t i = 0; i < mSize; i++) {
        mWords[i].free();
    }
}