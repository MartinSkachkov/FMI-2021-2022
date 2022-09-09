#ifndef _PAIR_H_
#define _PAIR_H_

class Pair {
private:
    char *mWord;
    char *mMeaning;

public:
    void wordInit(const char *word, const char *meaning);
    Pair copy() const;
    void print() const;
    void free();

    char *getWord() const { return mWord; }
    char *getMeaning() const { return mMeaning; }
};

#endif