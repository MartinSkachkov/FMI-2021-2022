#include <iostream>
#define DICT_SIZE 128
#define TEXT_SIZE 1024
#define CORRECTED_TEXT_SIZE 2048
using namespace std;

void transportationText(char* text, int indexStart, int indexEnd) {
    for (int i = indexEnd; i > indexStart; i--) {
        text[i] = text[i - 1];
    }
}

bool isPunctuationSymbol(char symbol) {
    const char punctSymbols[] = {'.', ',', '!', '?', ';', ':'};
    size_t punctSize = sizeof(punctSymbols) / sizeof(punctSymbols[0]);
    for (size_t i = 0; i < punctSize; i++) {
        if (symbol == punctSymbols[i]) {
            return true;
        }
    }
    return false;
}

void autoCorrect(char* text, char** dictionary, char*& correctedText,
                 size_t textSize, size_t dictSize) {
    bool isQuoteOpen = false;
    for (size_t i = 0; i < textSize; i++) {
        if (text[i] == '"') {
            isQuoteOpen = !isQuoteOpen;
        }
        if (isPunctuationSymbol(text[i])) {
            if (isQuoteOpen && !isPunctuationSymbol(text[i - 1])) {
                transportationText(text, i - 1, textSize);
                isQuoteOpen = false;
                textSize++;
            }
        }
    }
}

int main() {
    char dictionary[DICT_SIZE][101] = {0};
    char text[TEXT_SIZE + 1] = {0};
    char correctedText[CORRECTED_TEXT_SIZE + 1] = {0};

    size_t dictSize, textSize;
    do {
        cout << "dictionary size: ";
        cin >> dictSize;
        cout << "text size: ";
        cin >> textSize;
    } while ((dictSize < 0 || dictSize > DICT_SIZE) ||
             (textSize < 0 || textSize > TEXT_SIZE));

    cout << "enter the text:\n";
    cin.get();
    cin.getline(text, textSize);

    cout << "enter the dictionary(wrongWord-correctWord):\n";
    cin.get();
    for (size_t i = 0; i < dictSize; i++) {
        cin.getline(dictionary[i], 101);
    }

    cout << "corrected text:\n" << correctedText;
    return 0;
}