#include <iostream>
using namespace std;

void resetVisited(bool**& visited, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }
}

bool isSafe(bool** visited, size_t currX, size_t currY, size_t rows,
            size_t cols) {
    if ((currX >= 0 && currX < rows) && (currY >= 0 && currY < cols) &&
        visited[currX][currY] == 0) {
        return true;
    }
    return false;
}

void findPath(char** grid, bool**& visited, int& steps, size_t currX,
              size_t currY, size_t rows, size_t cols) {
    if (isSafe(visited, currX, currY, rows, cols)) {
        visited[currX][currY] = 1;
        switch (grid[currX][currY]) {
            case 'R':
                currY++;
                break;
            case 'L':
                currY--;
                break;
            case 'U':
                currX--;
                break;
            case 'D':
                currX++;
                break;
        }
        steps++;
        findPath(grid, visited, steps, currX, currY, rows, cols);
    }
    return;
}

size_t maxSteps(char** grid, bool**& visited, size_t& startX, size_t& startY,
                size_t rows, size_t cols) {
    int maxSteps = INT_MIN;
    // we will start from each square on the grid
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int steps = 0;
            findPath(grid, visited, steps, i, j, rows, cols);
            resetVisited(visited, rows, cols);
            steps--;  // actual steps, otherwise overflows with 1
            if (steps > maxSteps) {
                maxSteps = steps;
                startX = i;
                startY = j;
            }
        }
    }
    return maxSteps;
}

bool ValidateGrid(char** grid, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (grid[i][j] != 'L' && grid[i][j] != 'R' && grid[i][j] != 'U' &&
                grid[i][j] != 'D') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    size_t rows, cols;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;

    // creating and validating the map
    cout << "grid:\n";
    char** grid = new (nothrow) char*[rows];
    if (!grid) {
        cout << "Couldn't allocate memory";
        return -1;
    }
    for (size_t i = 0; i < rows; i++) {
        grid[i] = new (nothrow) char[cols];
        if (!grid[i]) {
            cout << "Couldn't allocate memory";
            return -1;
        }
        for (size_t j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    // could be done while allocating the memory but I think this is better
    if (!ValidateGrid(grid, rows, cols)) {
        cout << "Invalid grid! Should be only capital letters chars!\n";
        do {
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    cin >> grid[i][j];
                }
            }

        } while (!ValidateGrid(grid, rows, cols));
    }

    // creating bool matrix to mark the steps
    bool** visited = new (nothrow) bool*[rows];
    if (!visited) {
        cout << "Couldn't allocate memory";
        return -1;
    }
    for (size_t i = 0; i < rows; i++) {
        visited[i] = new (nothrow) bool[cols];
        if (!visited[i]) {
            cout << "Couldn't allocate memory";
            return -1;
        }
        for (size_t j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }

    // would be better to initialize it at the beginning to -1 if sth fails
    size_t startX = 1000, startY = 1000;
    cout << "maximum steps before falling: "
         << maxSteps(grid, visited, startX, startY, rows, cols) << '\n'
         << "starting position (" << startX << ',' << startY << ')';

    // deleting memory
    for (size_t i = 0; i < rows; i++) {
        delete[] grid[i];
        delete[] visited[i];
    }
    delete[] grid;
    delete[] visited;
    return 0;
}