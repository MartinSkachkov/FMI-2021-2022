#include <iostream>
using namespace std;

// MY FIRST SOLUTION - NEED CHANGES(LOOK ROBOT.CPP FOR VALID SOLUTION)

bool ValidInput(char** grid, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 'L' && grid[i][j] != 'R' && grid[i][j] != 'U' &&
                grid[i][j] != 'D') {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(int n, int m, int current_row,
                 int current_col)  // is within the bounds
{
    return current_row < 0 || current_row > n || current_col < 0 ||
           current_col > m;
}

int LongestPath(char** grid, int n, int m, bool** visited_square,
                int current_row, int current_col) {
    visited_square[current_row][current_col] =
        true;  // making the current square visited(setting it to 1)

    /*0123
     0RRRD
     1RUUD
     2URUD
     3ULLR */

    switch (grid[current_row][current_col]) {
        case 'L':
            current_col--;
            break;  // L <- ROBOT
        case 'R':
            current_col++;
            break;  // ROBOT -> R
        case 'U':
            current_row--;
            break;  // ROBOT ^
        case 'D':
            current_row++;
            break;  // ROBOT down

        default:
            cout << "Invalid direction!\n";
            break;
    }

    // Base case of recursion
    if (visited_square[current_row][current_col] ||
        isValidMove(n, m, current_row, current_col)) {
        return 1;  // 1 because the length of one move is 1;
    }

    return 1 +
           LongestPath(grid, n, m, visited_square, current_row, current_col);
}

int main() {
    int n, m;  // rows, cols
    do {
        cout << "N: ";
        cin >> n;
        cout << "M: ";
        cin >> m;
    } while (n <= 0 || m <= 0);

    char** grid = new char*[n];
    cout << "Enter the grid path:\n";
    for (int i = 0; i < n; i++) {
        grid[i] = new char[m];
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Validation of the input for the char matrix
    if (ValidInput(grid, n, m) == false) {
        cout << "Invalid input!\n";
        do {
            cout << "Enter the path again:\n";
            for (int i = 0; i < n; i++) {
                grid[i] = new char[m];
                for (int j = 0; j < m; j++) {
                    cin >> grid[i][j];
                }
            }
        } while (ValidInput(grid, n, m) == false);
    }

    // Bool matrix that will tell us if square of the grid is visited or not
    // (1-visited; 0-not visited)
    int moves_counter = 0;
    int max_moves = INT_MIN;
    int start_x = 0, start_y = 0;

    for (int rows = 0; rows < n; rows++)  // keeps track of rows
    {
        for (int cols = 0; cols < m; cols++)  // keeps track of columns
        {
            // initializing it to 0
            bool** visited_square = new bool*[n];
            for (int i = 0; i < n; i++) {
                visited_square[i] = new bool[m];
                for (int j = 0; j < m; j++) {
                    visited_square[i][j] =
                        0;  // set all the squares are not visited
                }
            }

            // finds the current length of the path
            int moves_counter =
                LongestPath(grid, n, m, visited_square, rows, cols);

            if (moves_counter > max_moves) {
                max_moves = moves_counter;
                // finds the starting point
                start_x = rows;
                start_y = cols;
            }

            // deleting the bool matrix
            for (int visited_row = 0; visited_row < n; visited_row++) {
                delete[] visited_square[visited_row];
            }
            delete[] visited_square;
        }
    }

    // Results
    cout << "The starting point of the longest path is: " << start_x << ','
         << start_y << endl;
    cout << "Count of moves: " << max_moves;

    for (int i = 0; i < n; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}