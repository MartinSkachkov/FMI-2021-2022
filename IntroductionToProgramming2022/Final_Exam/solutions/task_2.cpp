#include <cstring>
#include <iostream>
#define SUBWORD_SIZE 10
using namespace std;

const char numericWord[][SUBWORD_SIZE] = {"zero",  "one",  "two",  "three",
                                          "four",  "five", "six",  "seven",
                                          "eight", "nine", "plus", "minus"};

// works correctly
size_t digitsCount(int number) {
    size_t digCtr = 0;
    while (number != 0) {
        digCtr++;
        number /= 10;
    }
    return digCtr;
}

// works correctly
char* convertNumToStr(int number) {
    char* str = nullptr;
    size_t neededMem = digitsCount(number);
    bool isNegative = false;

    if (number < 0) {
        isNegative = true;
    }

    if (!isNegative) {
        str = new char[neededMem + 1];
        str[neededMem] = 0;
    } else {
        str = new char[neededMem + 2];
        str[neededMem + 1] = 0;
        str[0] = '-';
    }

    while (number != 0) {
        if (!isNegative) {
            str[neededMem - 1] = abs(number) % 10 + '0';
            neededMem--;
            number /= 10;
        } else {
            str[neededMem] = abs(number) % 10 + '0';
            neededMem--;
            number /= 10;
        }
    }
    return str;
}

// works correctly
int extractDigit(char* extractSubword, bool& isValidSubword) {
    // we start comparing the extracted subword with the matrix of words
    for (size_t i = 0; i < 10; i++) {
        // found a valid subword matching an english numeric word
        if (strcmp(extractSubword, numericWord[i]) == 0) {
            isValidSubword = true;
            switch (i) {
                case 0:
                    return 0;
                    break;
                case 1:
                    return 1;
                    break;
                case 2:
                    return 2;
                    break;
                case 3:
                    return 3;
                    break;
                case 4:
                    return 4;
                    break;
                case 5:
                    return 5;
                    break;
                case 6:
                    return 6;
                    break;
                case 7:
                    return 7;
                    break;
                case 8:
                    return 8;
                    break;
                case 9:
                    return 9;
                    break;
            }
        }
    }
    return -1;
}

char* calcExpression(char*& expression, size_t size, bool& isValidSubword) {
    char extractSubword[SUBWORD_SIZE] = {0};
    int currSubNum = 0, extractedDigit = 0, currCalculations = 0;
    size_t extractSubwordIter = 0;
    size_t plusIndex = 0;
    size_t minusIndex = 0;
    size_t minusCtr = 1;
    size_t checkCtr = 1;

    // extracting the numeric words and converting them to int
    for (size_t i = 0; i < size; i++) {
        extractSubword[extractSubwordIter++] = expression[i];
        extractedDigit = extractDigit(extractSubword, isValidSubword);
        if (isValidSubword) {
            currSubNum = currSubNum * 10 + extractedDigit;
            isValidSubword = false;
            extractedDigit = 0;
            for (size_t i = 0; i < extractSubwordIter; i++) {
                extractSubword[i] = 0;
            }
            extractSubwordIter = 0;
        }

        // here we will do the calculations when we reach 'plus' ot 'minus'
        if (extractedDigit == -1) {
            if (strcmp(extractSubword, "plus") == 0) {
                if (minusCtr > checkCtr) {
                    currCalculations -= currSubNum;
                    currSubNum = 0;
                }
                currCalculations += currSubNum;
                for (size_t i = 0; i < 4; i++) {
                    extractSubword[i] = 0;
                }
                extractSubwordIter = 0;
                currSubNum = 0;
                // to check what was the last operation
                plusIndex = i;
            }

            if (strcmp(extractSubword, "minus") == 0) {
                // the first substraction operation must take the abs of the
                // substraction abs(0-1)
                if (minusCtr == 1) {
                    currCalculations = abs(currCalculations - currSubNum);
                    minusCtr++;
                } else {
                    currCalculations -= currSubNum;
                }
                for (size_t i = 0; i < 5; i++) {
                    extractSubword[i] = 0;
                }
                extractSubwordIter = 0;
                currSubNum = 0;
                // to check what was the last operation
                minusIndex = i;
            }
        }
    }
    if (plusIndex > minusIndex) {
        currCalculations += currSubNum;
    } else {
        currCalculations -= currSubNum;
    }

    // freeing expression cuz we will save the result of calculations as a
    // string to it
    delete[] expression;
    expression = convertNumToStr(currCalculations);
    return expression;
    // return subNum;
}

int main() {
    bool isValidSubword = false;

    size_t size;
    cout << "expression size: ";
    cin >> size;

    cout << "expression: ";
    char* expression = new char[size + 1];
    cin.get();
    cin.getline(expression, size + 1);

    cout << calcExpression(expression, size, isValidSubword);

    delete[] expression;
    return 0;
}