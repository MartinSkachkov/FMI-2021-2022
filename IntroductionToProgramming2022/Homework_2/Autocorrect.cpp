#include <iostream>
using namespace std;

void autoCorrect(char* text, int textLength, char** dictionary,
                 int dictionaryLength) {
    bool isQuoteOpend = false;
    for (int i = 0; i < textLength; i++) {
        if (text[i] == '\"') isQuoteOpend = !isQuoteOpend;

        if (isCharPunctuation(text[i])) {
            if (isQuoteOpend && !isCharPunctuation(text[i - 1])) {
                transportationText(text, i - 1, textLength);
                isQuoteOpend = false;
                textLength++;
            }
            setOneIntervalAfterChar(text, textLength, i);
            setOneIntervalBeforeChar(text, textLength, i);

            if (i + 2 < textLength && text[i] != ',' && text[i + 2] >= 'a' &&
                text[i + 2] <= 'z') {
                text[i + 2] = text[i + 2] - 'a' + 'A';
            }
        } else if (text[i] == ' ' || i == 0) {
            int startIndex = i == 0 ? 0 : i + 1;
            checkGrammatic(text, startIndex, textLength, dictionary,
                           dictionaryLength);
        } else if (text[i] == '\n' && !isCharPunctuation(text[i - 1])) {
            transportationText(text, i - 1, textLength);
            text[i - 1] = '.';
            textLength++;
        }
    }

    if (text[textLength - 2] == '\"' &&
        !isCharPunctuation(text[textLength - 3])) {
        transportationText(text, textLength - 3, textLength);
        text[textLength - 2] = '.';
        textLength++;
    }
    if (!isCharPunctuation(text[textLength])) {
        text[textLength] = '.';
    }
}

void checkGrammatic(char* text, int startIndex, int& textLength,
                    char** dictionary, int dictionaryLength) {
    int indexOfWord = indexOfDictionary(text, startIndex, textLength,
                                        dictionary, dictionaryLength);
    if (indexOfWord != -1) {
        replaceWord(text, textLength, startIndex, dictionary[indexOfWord]);
    }
}

int indexOfDictionary(char* text, int startIndex, int textlength,
                      char** dictionary, int dictionaryLength) {
    for (int i = 0; i < dictionaryLength; i++) {
        bool isContains = false;
        int index = 0;
        while (dictionary[i][index] == text[startIndex + index]) {
            if (dictionary[i][index + 1] == '-') {
                if (text[startIndex + index + 1] == ' ' ||
                    isCharPunctuation(text[startIndex + index + 1])) {
                    isContains = true;
                }

                break;
            }
            index++;
        }

        if (isContains) {
            return i;
        }
    }

    return -1;
}

void replaceWord(char* text, int& textLength, int startIndex, char* word) {
    int oldWordLength = getOldWordLength(word);
    int indexNewWord = oldWordLength + 2, newWordLength = 0;
    int indexOfText = startIndex;
    while (word[indexNewWord] != '\0') {
        if (indexNewWord - oldWordLength - 2 <= 0) {
            transportationText(text, indexOfText, textLength);
            textLength++;
        }

        text[indexOfText] = word[indexNewWord];
        indexNewWord++;
        newWordLength++;
        indexOfText++;
    }

    while (oldWordLength - newWordLength >= -1) {
        transportationTextLeftToRigth(text, indexOfText - 1, textLength);
        textLength--;
        newWordLength++;
    }
}

int getOldWordLength(char* word) {
    int index = 0;
    while (word[index + 1] != '-') {
        index++;
    }

    return index;
}

void removeIntervalsBeforeChar(char* text, int& textLength, int index) {
    bool firstInterval = true;
    while (index < textLength - 1 && text[index + 1] != ' ') {
        if (!firstInterval) {
            transportationText(text, index, textLength);
            textLength++;
            text[index + 1] = ' ';
        }
        firstInterval = false;
    }
}

void setOneIntervalAfterChar(char* text, int& textLength, int index) {
    bool firstInterval = true;
    while (index < textLength - 1 && text[index + 1] != ' ') {
        if (!firstInterval) {
            transportationText(text, index, textLength);
            textLength++;
            text[index + 1] = ' ';
        }
        firstInterval = false;
    }
}

void setOneIntervalBeforeChar(char* text, int& textLength, int& index) {
    while (index > 1 && text[index - 1] == ' ') {
        transportationTextLeftToRigth(text, index - 1, textLength);
        text[textLength] = 0;
        textLength--;
        index--;
    }
}

bool isCharPunctuation(char ch) {
    const char PUNCTUATION_MARKS[] = {'.', ',', '!',
                                      '?', ';', ':'};  //, '(', ')', '\"', '\''
    for (int i = 0;
         i < sizeof(PUNCTUATION_MARKS) / sizeof(PUNCTUATION_MARKS[0]); i++) {
        if (ch == PUNCTUATION_MARKS[i]) {
            return true;
        }
    }

    return false;
}

void transportationText(char* text, int indexStart, int indexEnd) {
    for (int i = indexEnd; i > indexStart; i--) {
        text[i] = text[i - 1];
    }
}

void transportationTextLeftToRigth(char* text, int indexStart, int indexEnd) {
    for (int i = indexStart; i < indexEnd; i++) {
        text[i] = text[i + 1];
    }
}

int main() {
    int const MAX_TEXT_SIZE = 2049;
    int const MAX_DICTIONARY_SIZE = 128;
    int const MAX_LENGTH_OF_DIRCTIONARY_WORLDS = 100;
    char text[MAX_TEXT_SIZE] =
        "Once upon a time there lived in a certain village a little country "
        "girl, the pritiest creature who was ever seen. Her mother was "
        "excessively fond of her; and her grandmother doted on her still "
        "more.This good woman had a little red riding hood made for her. It "
        "suited the girl so extremely well that everybody called her little "
        "red riding hood. One day her mother, having made some cakes, said to "
        "her,\"Go, my dear, and see how your grandmother is doing, for I hear "
        "she has been very ill.Take her a cake, and this little pot of "
        "butter\"";
    int textLength = 534;
    int dicationaryLength = 4;
    char** dictionary =
        new char* [] {  //[MAX_DICTIONARY_SIZE][MAX_LENGTH_OF_DIRCTIONARY_WORLDS]
                        //{
            new char[]{"stil-still"}, new char[]{"pritiest-prettiest"},
                new char[]{"little red riding hood-Little Red Riding Hood"},
                new char[]{"leafes-leaves"},
        };

    autoCorrect(text, textLength, dictionary, dicationaryLength);
    cout << text;

    return 0;
}