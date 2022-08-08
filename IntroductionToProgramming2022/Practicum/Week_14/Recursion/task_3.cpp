#include <iostream>
using namespace std;

bool safePosition(char** maze, size_t currRow, size_t currCol, size_t destRow,
                  size_t destCol) {
    // if we are within the bounds of the maze and the current position is '.'
    // everything is ok
    if ((currRow >= 0 && currRow <= destRow) &&
        (currCol >= 0 && currCol <= destCol) &&
        (maze[currRow][currCol] == '.')) {
        return true;
    }
    return false;
}

bool findPath(char** maze, bool** path, size_t currRow, size_t currCol,
              size_t destRow, size_t destCol) {
    // base case
    if (currRow == destRow && currCol == destCol) {
        path[currRow][currCol] = 1;
        return true;  // found a path to the end
    }

    // if we are not at the end
    if (safePosition(maze, currRow, currCol, destRow, destCol) == true) {
        if (path[currRow][currCol] == 1) {
            return false;
        }
        path[currRow][currCol] = 1;

        if (findPath(maze, path, currRow + 1, currCol, destRow, destCol) ==
            true) {
            return true;
        }
        if (findPath(maze, path, currRow - 1, currCol, destRow, destCol) ==
            true) {
            return true;
        }
        if (findPath(maze, path, currRow, currCol + 1, destRow, destCol) ==
            true) {
            return true;
        }
        if (findPath(maze, path, currRow, currCol - 1, destRow, destCol) ==
            true) {
            return true;
        }
        path[currRow][currCol] = 0;
        return false;
    }
    return false;
}

void print(bool** path, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << path[i][j] << ' ';
        }
        cout << "\n";
    }
}

int main() {
    // size of the maze
    size_t rows, cols;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;

    // initializing maze
    cout << "maze:\n";
    char** maze = new (nothrow) char*[rows];
    if (!maze) {
        cout << "Couldn't allocate memory";
        return -1;
    }
    for (size_t i = 0; i < rows; i++) {
        maze[i] = new (nothrow) char[cols];
        if (!maze[i]) {
            cout << "Couldn't allocate memory";
            return -1;
        }
        for (size_t j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    // array to mark the walked path (at the begining it is all 0)
    bool** path = new (nothrow) bool*[rows];
    if (!path) {
        cout << "Couldn't allocate memory";
        return -1;
    }
    for (size_t i = 0; i < rows; i++) {
        path[i] = new (nothrow) bool[cols];
        if (!path) {
            cout << "Couldn't allocate memory";
            return -1;
        }
        for (size_t j = 0; j < cols; j++) {
            path[i][j] = 0;
        }
    }

    size_t destRow = rows - 1;
    size_t destCol = cols - 1;

    cout << boolalpha << "Is there a path? "
         << findPath(maze, path, 0, 0, destRow, destCol) << "\n";
    cout << noboolalpha << "found path:\n";
    print(path, rows, cols);

    // freeing memory
    for (size_t i = 0; i < rows; i++) {
        delete[] maze[i];
        delete[] path[i];
    }
    delete[] maze;
    delete[] path;
    return 0;
}