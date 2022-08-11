#include <cstring>
#include <iostream>
#define INPUT_SIZE 30
using namespace std;

size_t calcDigits(size_t number) {
    size_t digits = 0;
    while (number != 0) {
        digits++;
        number /= 10;
    }
    return digits;
}

char* numToStr(size_t number) {
    int size = calcDigits(number);
    char* result = new char[size + 1];
    result[size] = 0;

    while (number != 0) {
        // '5'   int(5)
        result[size - 1] = char(number % 10 + int('0'));
        size--;
        number /= 10;
    }
    return result;
}

size_t calcCompressedSize(char* input) {
    size_t wholeSize = 0, currSize = 1;
    //!!!looping might get aout of the array!!!
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] == input[i + 1]) {
            currSize++;
        }
        // we finished with a repeating section and want to save the currSize to
        // wholeSize
        if (input[i] != input[i + 1]) {
            // case when we have only a single letter in the sequence
            if (currSize == 1) {
                // saving space just for the letter
                wholeSize++;
            } else {
                // 1 for the letter + number of digits for the length of the
                // repeating letters
                wholeSize += (1 + calcDigits(currSize));
                currSize = 1;
            }
        }
    }

    /* when we loop till strlen(input) - 1
    if(currSize == 1)
    {
            finalStringSize++;
    }
    else // currentSize > 1
    {
            //a20
            finalStringSize += (1 + toStringLen(currentSize));
    }*/
    return wholeSize;
}

char* compress(char* input) {
    char* compressed = new char[calcCompressedSize(input) + 1];

    size_t currSize = 1;
    size_t compressedIter = 0;
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] == input[i + 1]) {
            currSize++;
        }
        if (input[i] != input[i + 1]) {
            compressed[compressedIter++] = input[i];  // add the letter
            // case when we want to add the number of letters
            if (currSize > 1) {
                char* number = numToStr(currSize);
                for (size_t i = 0; i < strlen(number); i++) {
                    compressed[compressedIter] = number[i];
                    compressedIter++;
                }
                currSize = 1;
                delete[] number;
            }
        }
    }

    /*we need to add that if we will loop till strlen(input) - 1;
    compressed[compressedIter++] = input[i];  // add the letter
            // case when we want to add the number of letters
            if (currSize > 1) {
                    char* number = numToStr(currSize);
                    for (size_t i = 0; i < strlen(number); i++) {
                            compressed[compressedIter++] = number[i];
                    }
                    currSize = 1;
                    delete[] number;
            }
    }*/

    compressed[compressedIter] = 0;
    return compressed;
}

int main() {
    cout << "input: ";
    char* input = new char[INPUT_SIZE];
    cin.getline(input, INPUT_SIZE);
    cout << calcCompressedSize(input) << '\n';

    char* compressed = compress(input);
    cout << "compressed string: " << compressed;

    delete[] compressed;
    delete[] input;
    return 0;
}