#include <iostream>
using namespace std;

bool canFulfillRequest(int truckCapacity, int woodVal, int maxCapacity) {
    truckCapacity += woodVal;
    if (truckCapacity >= 0 && truckCapacity <= maxCapacity) {
        return true;
    }
    return false;
}

bool inTown(int** map, size_t currX, size_t currY, size_t n, int truckCapacity,
            int maxCapacity) {
    if (currX >= 0 && currX < n && currY >= 0 && currY < n &&
        canFulfillRequest(truckCapacity, map[currX][currY], maxCapacity))
        return true;
    return false;
}

bool findPath(int** map, bool** visited, size_t n, size_t currX, size_t currY,
              size_t endX, size_t endY, int& truckCapacity, int maxVolume) {
    if (currX == endX && currY == endY &&
        canFulfillRequest(truckCapacity, map[currX][currY], maxVolume)) {
        truckCapacity += map[currX][currY];
        visited[currX][currY] = 1;
        return true;
    }

    if (inTown(map, currX, currY, n, truckCapacity, maxVolume)) {
        if (visited[currX][currY]) {
            return false;
        }
        visited[currX][currY] = 1;

        truckCapacity += map[currX][currY];

        if (findPath(map, visited, n, currX + 1, currY, endX, endY,
                     truckCapacity, maxVolume) == true) {
            return true;
        }

        if (findPath(map, visited, n, currX - 1, currY, endX, endY,
                     truckCapacity, maxVolume) == true) {
            return true;
        }

        if (findPath(map, visited, n, currX, currY + 1, endX, endY,
                     truckCapacity, maxVolume) == true) {
            return true;
        }
        // truckCapacity -= map[currX][currY];
        if (findPath(map, visited, n, currX, currY - 1, endX, endY,
                     truckCapacity, maxVolume) == true) {
            return true;
        }

        // If none of the above movements work then
        // BACKTRACK: unmark x, y as part of solution path
        visited[currX][currY] = 0;
        truckCapacity -= map[currX][currY];
        return false;
    }
    return false;
}

void printMap(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

// could be done with templates but that is for OOP
void printVisited(bool** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

// works partially
int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n >= 128);

    // map initialization
    cout << "map:\n";
    int** map = new (nothrow) int*[n];
    if (!map) {
        cout << "Couldn't allocate memory!";
        return -1;
    }
    for (size_t i = 0; i < n; i++) {
        map[i] = new (nothrow) int[n];
        if (!map[i]) {
            cout << "Couldn't allocate memory!";
            return -1;
        }
        for (size_t j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // print(map, n);

    // start pos
    size_t homeRow, homeCol;
    do {
        cout << "home row: ";
        cin >> homeRow;
        cout << "home col: ";
        cin >> homeCol;
    } while ((homeRow < 1 || homeRow > n) || (homeCol < 1 || homeCol > n));

    // truck capacity checks
    int maxVolume;
    cout << "maximum truck volume: ";
    cin >> maxVolume;

    if (maxVolume < map[homeRow - 1][homeCol - 1] ||
        map[homeRow - 1][homeCol - 1] < 0) {
        cout << "Ivalid home position!";
        return -1;
    }

    int startCapacity = map[homeRow - 1][homeCol - 1];
    int truckCapacity = 0;
    cout << "starting truck capacity: " << startCapacity << '\n';

    // final pos
    size_t grannyRow, grannyCol;
    do {
        cout << "granny row: ";
        cin >> grannyRow;
        cout << "granny col: ";
        cin >> grannyCol;
    } while ((grannyRow < 1 || grannyRow > n) ||
             (grannyCol < 1 || grannyCol > n));

    // tracking route
    bool** visited = new (nothrow) bool*[n];
    if (!visited) {
        cout << "Couldn't allocate memory!";
        return -1;
    }
    for (size_t i = 0; i < n; i++) {
        visited[i] = new (nothrow) bool[n];
        if (!visited[i]) {
            cout << "Couldn't allocate memory!";
            return -1;
        }
        for (size_t j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    bool HomeToGranny =
        findPath(map, visited, n, homeRow - 1, homeCol - 1, grannyRow - 1,
                 grannyCol - 1, truckCapacity, maxVolume);

    cout << "home -> granny: " << boolalpha << HomeToGranny << '\n'
         << noboolalpha;
    printVisited(visited, n);
    cout << '\n' << "truck capacity: " << truckCapacity << '\n';

    // make the start and end not visited
    visited[homeRow - 1][homeCol - 1] = 0;
    visited[grannyRow - 1][grannyCol - 1] = 0;

    bool GrannyToHome =
        findPath(map, visited, n, grannyRow - 1, grannyCol - 1, homeRow - 1,
                 homeCol - 1, truckCapacity, maxVolume);
    cout << "granny -> home: " << boolalpha << GrannyToHome << '\n'
         << noboolalpha;
    printVisited(visited, n);
    cout << '\n' << "truck capacity: " << truckCapacity << '\n';

    // while(!HomeToGranny ||!GrannyToHome){
    //     if(!HomeToGranny){

    //     }
    // }

    for (size_t i = 0; i < n; i++) {
        delete[] map[i];
        delete[] visited[i];
    }
    delete[] visited;
    delete[] map;
    return 0;
}