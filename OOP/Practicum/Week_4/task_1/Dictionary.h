#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#define MAX_PAIR_SIZE 500
#include "Pair.h"

class Dictionary {
private:
    Pair mWords[MAX_PAIR_SIZE];
    unsigned mSize;

public:
    void init(Pair *words, const int &size);
    void print() const;
    bool add(const Pair &newPair);
    bool remove(const char *word);
    char *findMeaning(const char *word) const;             // getter
    char *findMeaningByIndex(const unsigned &index) const; // getter
    void sort();
    void free();
};

#endif