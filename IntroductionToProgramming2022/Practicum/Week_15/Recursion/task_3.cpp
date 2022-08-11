#include <cstring>
#include <iostream>
#define PATH_SIZE 20
using namespace std;

bool validatePath(char* path) {
    for (size_t i = 0; i < strlen(path); i++) {
        if (path[i] != 'E' && path[i] != 'W' && path[i] != 'N' &&
            path[i] != 'S') {
            return false;
        }
    }
    return true;
}

bool isSafePosition(bool** maze, size_t n, size_t x, size_t y) {
    if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1) {
        return true;
    }
    return false;
}

bool findPath(bool** maze, bool** visited, char* path, size_t n, size_t x,
              size_t y, int& startX, int& startY, size_t pathLen,
              size_t originalPathLen, size_t steps) {
    if (steps == originalPathLen) {
        startX = x;
        startY = y;
        return true;
    }
    // we start from the bottom right
    // if we can step there and this place is not visited, we go there
    if (isSafePosition(maze, n, x, y)) {
        if (visited[x][y]) {
            return false;
        }
        // we mark is as visited
        visited[x][y] = 1;
        startX = x;
        startY = y;

        switch (path[pathLen - 1]) {
            case 'E':
                y--;
                break;
            case 'W':
                y++;
                break;
            case 'N':
                x++;
                break;
            case 'S':
                x--;
                break;
        }

        steps++;
        return findPath(maze, visited, path, n, x, y, startX, startY,
                        pathLen - 1, originalPathLen, steps);
    }
    return false;
}

void free(bool** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    size_t n;
    cout << "n: ";
    cin >> n;

    cout << "maze:\n";
    bool** maze = new bool*[n];
    for (size_t i = 0; i < n; i++) {
        maze[i] = new bool[n];
        for (size_t j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    char path[PATH_SIZE];
    cout << "path: ";
    cin.get();
    cin.getline(path, PATH_SIZE);
    if (validatePath(path) == false) {
        cout << "Invalid path!";
        return 1;
    }
    size_t pathLen = strlen(path);
    size_t originalPathLen = pathLen;

    bool** visited = new bool*[n];
    for (size_t i = 0; i < n; i++) {
        visited[i] = new bool[n];
        for (size_t j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    int startX = -1, startY = -1;
    cout << "Has path? " << boolalpha
         << findPath(maze, visited, path, n, n - 1, n - 1, startX, startY,
                     pathLen, originalPathLen, 0)
         << '\n';
    cout << "starting position:\n"
         << "x: " << startX << '\n'
         << "y: " << startY;

    free(maze, n);
    free(visited, n);
    return 0;
}