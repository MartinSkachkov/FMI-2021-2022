#include <iostream>
using namespace std;

void initialize(char** box, size_t n) {
    for (size_t i = 0; i < n; i++) {
        box[i] = new char[n];
        for (size_t j = 0; j < n; j++) {
            cin >> box[i][j];
        }
    }
}

bool isFixed(char** shuffled, char** box, size_t n) {
    // increase and then decrement and if there is no change the count is the
    // same
    for (size_t i = 0; i < n; i++) {
        size_t white = 0, milk = 0, dark = 0;
        for (size_t j = 0; j < n; j++) {
            switch (box[i][j]) {
                case 'W':
                    white++;
                    break;
                case 'M':
                    milk++;
                    break;
                case 'D':
                    dark++;
                    break;
            }
            switch (shuffled[i][j]) {
                case 'W':
                    white--;
                    break;
                case 'M':
                    milk--;
                    break;
                case 'D':
                    dark--;
                    break;
            }
        }
        if (white != 0 || dark != 0 || milk != 0) {
            return false;
        }
    }
    return true;
}

void free(char** box, size_t n) {
    for (size_t i = 0; i < n; i++) {
        delete[] box[i];
    }
    delete[] box;
}

int main() {
    size_t n;
    cout << "n: ";
    cin >> n;

    char** box = new char*[n];
    cout << "box:\n";
    initialize(box, n);

    char** shuffled = new char*[n];
    cout << "shuffled:\n";
    initialize(shuffled, n);

    if (isFixed(shuffled, box, n)) {
        cout << "fixed";
    } else {
        cout << "not fixed";
    }

    free(box, n);
    free(shuffled, n);
    return 0;
}