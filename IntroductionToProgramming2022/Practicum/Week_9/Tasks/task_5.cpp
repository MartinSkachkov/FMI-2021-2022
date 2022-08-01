#include <iostream>
using namespace std;

int* histogram(char* text, int size) {
    int* histogram =
        new int[128];  // array of ascii chart, keeping track of elements
    for (size_t i = 0; i < 128; i++) {
        histogram[i] = 0;
    }

    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < size; j++) {
            if (text[j] == (char)i) {
                histogram[i]++;
            }
        }
    }
    return histogram;  // return a copy of a pointer to this location in memory
}

void print(const int* result) {
    for (size_t i = 65; i <= 90; i++) {
        cout << (char)i << "->" << result[i] << endl;
    }

    for (size_t i = 97; i <= 122; i++) {
        cout << (char)i << "->" << result[i] << endl;
    }
}

int main() {
    size_t size;
    cout << "size: ";
    cin >> size;

    cout << "text: ";
    char* text = new char[size + 1];
    cin.get();
    cin.getline(text, size + 1);

    int* result = histogram(text, size);

    print(result);

    delete[] result;
    delete[] text;
    return 0;
}