#include <cstring>
#include <iostream>
using namespace std;

bool validatePath(char* path) {
    for (int i = 0; i < strlen(path); i++) {
        if (path[i] != 'E' && path[i] != 'W' && path[i] != 'N' &&
            path[i] != 'S') {
            return false;
        }
    }
    return true;
}

bool isValidSituation(bool** matrix, int n, int startX, int startY) {
    return startX >= 0 && startY >= 0 && startX <= n - 1 && startY <= n - 1 &&
           matrix[startX][startY] == 1;
}

bool hasPath(bool** matrix, int n, char* path) {
    // let's start from bottom right
    //  and traverse the path backwords
    int startX = n - 1;
    int startY = n - 1;
    // EEWEWSU
    for (int i = strlen(path) - 1; i >= 0; i--) {
        if (isValidSituation(matrix, n, startX, startY) == false) {
            return false;
        }

        switch (path[i]) {
            case 'E':
                startY--;
                break;  // go west
            case 'W':
                startY++;
                break;  // go east
            case 'N':
                startX++;
                break;  // go south
            case 'S':
                startX--;
                break;  // go north
        }
    }
    cout << "Starting postion: " << startX << "," << startY << endl;
    return true;
}
int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;
    bool** matrix = new bool*[size];
    for (size_t i = 0; i < size; i++) {
        matrix[i] = new bool[size];
        for (size_t j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }

    char path[20];
    cin >> path;

    if (validatePath(path) == false) {
        cout << "Invalid path!";
        return 1;
    }

    cout << "Has path? " << boolalpha << hasPath(matrix, size, path);

    for (size_t i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}