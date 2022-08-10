#include <cstring>
#include <iostream>
#define MAX_INPUT 1024
using namespace std;

int getLetterIndex(char* letter, int n, char currLetter) {
    for (int i = 0; i < n; i++) {
        if (*(letter + i) == currLetter) {
            return i;
        }
    }
    // if the letter is not existing in the array
    return -1;
}

size_t calculate(char* algebraicExpression, char* letters, size_t* values,
                 int n) {
    size_t currSum = 0;
    size_t currMulti = 1;
    for (size_t i = 0; i < strlen(algebraicExpression); i++) {
        // we add the result of multiplication to the sum
        if (algebraicExpression[i] == '+') {
            currSum += currMulti;
            currMulti = 1;
        }
        // calculating the product
        else if (algebraicExpression[i] >= 'a' &&
                 algebraicExpression[i] <= 'z') {
            int letterIndex =
                getLetterIndex(letters, n, algebraicExpression[i]);
            currMulti *= letterIndex != -1 ? values[letterIndex] : 0;
        }
    }
    return currSum + currMulti;
}

int main() {
    char algebraicExpression[MAX_INPUT] = {'\0'};
    char letters[MAX_INPUT] = "";
    size_t values[MAX_INPUT] = {0};

    int count;
    cout << "letters and values count: ";
    cin >> count;

    cout << "letters: ";
    for (size_t i = 0; i < (size_t)count; i++) {
        cin >> letters[i];
    }

    cout << "numbers: ";
    for (size_t i = 0; i < (size_t)count; i++) {
        cin >> values[i];
    }

    cout << "algebraicExpression: ";
    cin.get();
    cin.getline(algebraicExpression, MAX_INPUT);

    size_t result = calculate(algebraicExpression, letters, values, count);
    cout << "result: " << result;
    return 0;
}