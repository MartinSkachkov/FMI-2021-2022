#include <iostream>
#define MAX_MOVES 30
using namespace std;

size_t strlen(char* str) {
    size_t len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

bool validatePath(char* path) {
    for (size_t i = 0; i < strlen(path); i++) {
        if (path[i] != 'E' && path[i] != 'W' && path[i] != 'N' &&
            path[i] != 'S') {
            return false;
        }
    }
    return true;
}

bool isSafe(bool** maze, size_t currX, size_t currY, size_t endX, size_t endY) {
    if ((currX >= 0 && currX <= endX) && (currY >= 0 && currY <= endY) &&
        maze[currX][currY] == 1) {
        return true;
    }
    return false;
}

bool hasPath(char* path, bool** maze, const size_t startX, const size_t startY,
             const size_t endX, const size_t endY) {
    size_t currX = endX, currY = endY;
    for (size_t i = strlen(path) - 1; i >= 0; i--) {
        if (isSafe(maze, currX, currY, endX, endY) == false) {
            return false;
        }
        switch (path[i]) {
            case 'E':
                currY--;
                break;
            case 'W':
                currY++;
                break;
            case 'N':
                currX++;
                break;
            case 'S':
                currX--;
                break;
        }
        if (isSafe(maze, currX, currY, endX, endY) && startX == currX &&
            startY == currY) {
            return true;
        }
    }
}

int main() {
    size_t rows, cols;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;

    cout << "enter the maze:\n";
    bool** maze = new (nothrow) bool*[rows];
    if (!maze) {
        cout << "couldn't allocate memory";
        return -1;
    }
    for (size_t i = 0; i < rows; i++) {
        maze[i] = new (nothrow) bool[cols];
        if (!maze[i]) {
            cout << "couldn't allocate memory";
            return -1;
        }
        for (size_t j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    cout << "path:";
    char path[MAX_MOVES] = "";
    cin.ignore();
    cin.getline(path, MAX_MOVES);
    if (validatePath(path) == false) {
        cout << "Invalid path!";
        return 1;
    }

    size_t startX, startY, endX, endY;
    endX = rows - 1;
    endY = cols - 1;

    cout << "x: ";
    cin >> startX;
    cout << "y: ";
    cin >> startY;

    cout << boolalpha << "Has Path? "
         << hasPath(path, maze, startX - 1, startY - 1, endX, endY);

    for (size_t i = 0; i < rows; i++) {
        delete[] maze[i];
    }
    delete[] maze;
    return 0;
}