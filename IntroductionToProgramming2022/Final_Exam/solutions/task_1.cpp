#include <cstring>
#include <iostream>
#define MAX_CAPACITY 1024
using namespace std;

// rgyrggrygr
//  ggrrgyrgyr

bool validPathInput(char* sequence) {
    for (size_t i = 0; i < strlen(sequence); i++) {
        if (sequence[i] != 'g' && sequence[i] != 'r' && sequence[i] != 'y') {
            return false;
        }
    }
    return true;
}

size_t maxMoves(char* sequence) {
    size_t sequenceLength = strlen(sequence);
    int moves = 0, maxMoves = INT_MIN;

    for (size_t tries = 0; tries < sequenceLength; tries++) {
        for (size_t robotPos = tries; robotPos <= sequenceLength; robotPos++) {
            if (sequence[robotPos] == 'g') {
                if (sequence[robotPos + 1] == 0 ||
                    sequence[robotPos + 1] == 'r') {
                    moves++;
                    break;  // attempt failed
                }
                moves++;
                continue;  // successful step
            }

            if (sequence[robotPos] == 'y') {
                while (sequence[robotPos + 1] != 'g') {
                    if (sequence[robotPos + 1] == 0) {
                        moves--;
                        break;
                    }
                    robotPos++;
                }
                moves++;
                continue;
            }

            if (sequence[robotPos] == 'r') {
                break;
            }
        }
        // calculating the maximum moves after each try
        if (moves > maxMoves) {
            maxMoves = moves;
        }
        moves = 0;
    }
    return maxMoves;
}

int main() {
    char sequence[MAX_CAPACITY + 1] = {0};  //+1 for \0
    do {
        cout << "Enter the colorized sequence: ";
        cin.getline(sequence, MAX_CAPACITY);
    } while (!validPathInput(sequence));

    cout << "Maximum moves: " << maxMoves(sequence);
    return 0;
}