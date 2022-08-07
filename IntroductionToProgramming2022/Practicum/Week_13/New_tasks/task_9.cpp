#include <iostream>
using namespace std;

bool isValidPosition(char** maze, size_t currRow, size_t currCol, size_t rows,
                     size_t cols) {
    // within the bounds of the maze and the current position can be stepped on
    if ((currRow >= 0 && currRow < rows) && (currCol >= 0 && currCol < cols) &&
        (maze[currRow][currCol] == '.')) {
        return true;
    }
    return false;
}

bool hasPath(char** maze, bool** path, size_t currRow, size_t currCol,
             size_t rowDest, size_t colDest, size_t rows, size_t cols) {
    // base case - found the final destination
    if (currRow == rowDest && currCol == colDest) {
        // save the final position to the solution path
        path[currRow][currCol] = 1;
        return true;
    }

    // if we haven't found the final destination
    if (isValidPosition(maze, currRow, currCol, rows, cols) == true) {
        // Check if the current block is already part of
        // solution path.
        if (path[currRow][currCol] == 1) {
            return false;
        }
        // mark x, y as part of solution path
        path[currRow][currCol] = 1;

        if (hasPath(maze, path, currRow + 1, currCol, rowDest, colDest, rows,
                    cols) == true) {
            return true;
        }
        if (hasPath(maze, path, currRow - 1, currCol, rowDest, colDest, rows,
                    cols) == true) {
            return true;
        }
        if (hasPath(maze, path, currRow, currCol + 1, rowDest, colDest, rows,
                    cols) == true) {
            return true;
        }
        if (hasPath(maze, path, currRow, currCol - 1, rowDest, colDest, rows,
                    cols) == true) {
            return true;
        }

        // if none of the conditions were met
        path[currRow][currCol] = 0;
        return false;
    }
    return false;
}

void printSolution(bool** path, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << path[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // maze size
    size_t rows, cols;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;

    // initialize the maze
    char** maze = new char*[rows];
    cout << "maze:\n";
    for (size_t i = 0; i < rows; i++) {
        maze[i] = new char[cols];
        for (size_t j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    // setting final destination
    size_t rowDest, colDest;
    do {
        cout << "final row destination: ";
        cin >> rowDest;
        cout << "final column destination: ";
        cin >> colDest;
        rowDest--;
        colDest--;
    } while ((rowDest < 0 || rowDest > rows) &&
             (colDest < 0 || colDest > cols));

    // bool matrix to keep track of the path
    bool** path = new bool*[rows];
    for (size_t i = 0; i < rows; i++) {
        path[i] = new bool[cols];
        for (size_t j = 0; j < cols; j++) {
            path[i][j] = 0;
        }
    }

    // printing if a valid path is existing
    // start destination is 0, 0
    cout << boolalpha << "Has Path? "
         << hasPath(maze, path, 0, 0, rowDest, colDest, rows, cols) << "\n";

    cout << noboolalpha << "///////////////////////"
         << "\n";
    printSolution(path, rows, cols);

    for (size_t i = 0; i < rows; i++) {
        delete[] maze[i];
        delete[] path[i];
    }
    delete[] maze;
    delete[] path;

    return 0;
}