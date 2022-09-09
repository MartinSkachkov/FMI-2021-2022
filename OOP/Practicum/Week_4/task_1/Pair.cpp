#include "Pair.h"
#include <cstring>
#include <iostream>
#define MAX_SIZE 15
using namespace std;

void Pair::wordInit(const char *word, const char *meaning) {
    mWord = new char[strlen(word) + 1];
    strcpy(mWord, word);
    mWord[strlen(word)] = 0;

    mMeaning = new char[strlen(meaning) + 1];
    strcpy(mMeaning, meaning);
    mMeaning[strlen(meaning)] = 0;
}

Pair Pair::copy() const {
    Pair copy;
    copy.mWord = new char[strlen(mWord) + 1];
    strcpy(copy.mWord, mWord);
    copy.mWord[strlen(mWord)] = 0;

    copy.mMeaning = new char[strlen(mMeaning) + 1];
    strcpy(copy.mMeaning, mMeaning);
    copy.mMeaning[strlen(mMeaning)] = 0;

    return copy;
}

void Pair::print() const {
    cout << mWord << " - " << mMeaning;
}

void Pair::free() {
    delete[] mWord;
    delete[] mMeaning;
}

/*void resetInput(char *input) {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        input[i] = 0;
    }
}

void Word::wordInit() {
    cout << "Word: ";
    char input[MAX_SIZE] = {0};
    cin.getline(input, MAX_SIZE);
    mWord = new char[strlen(input) + 1];
    strcpy(mWord, input);

    cout << "Meaning of " << mWord << " : ";
    resetInput(input);
    cin.getline(input, MAX_SIZE);
    mMeaning = new char[strlen(input) + 1];
    strcpy(mMeaning, input);
}*/