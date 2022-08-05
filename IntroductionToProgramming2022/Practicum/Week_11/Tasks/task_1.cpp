#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

int KingsSum(int[8][8], int, int);

// DO NOT CHANGE ANYTHING INSIDE OF MAIN EXCEPT THE VALUES OF ROW AND COL
int main() {
    int row, col;
    int board[8][8];

    string colIndices = "           0    1    2    3    4    5    6    7";

    // Generate a random board full of numbers in the range of -100 to 100.
    // Used as a visual for students so they can check if their algorithm in
    // the KingsSum function is correct.

    cout << right << endl << endl << colIndices << endl;
    cout << "       ----------------------------------------" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << setw(5) << i << " |";
        for (int j = 0; j < 8; ++j) {
            board[i][j] = (rand() % 201) - 100;
            cout << setw(5) << board[i][j];
        }
        if (i < 7)
            cout << endl << "      |" << endl;
        else
            cout << endl << endl << endl;
    }

    // Change these values to test your algorithm
    row = 1;
    col = 1;

    cout << "The sum of all the squares at and around the King at (" << row << ", " << col << ") is: ";
    cout << KingsSum(board, row, col) << endl;

} // End of main

// DO NOT write any cout statements in here. Only your algorithm
int KingsSum(int board[8][8], int row, int col)
{
    int sum = board[row][col];
    if (((row == row - 1) || (row == row + 1)) && ((col == col - 1) || (col == col + 1))) {
        sum += board[row][col];
    }
    if (row > 0, col > 0) sum += board[row - 1][col - 1];
    if (row < 7, col > 0) sum += board[row + 1][col - 1];
    if (row > 0, col < 7) sum += board[row - 1][col + 1];
    if (row < 7, col < 7) sum += board[row + 1][col + 1];
    if (row > 0) sum += board[row - 1][col];
    if (row < 7) sum += board[row + 1][col];
    if (col > 0) sum += board[row][col - 1];
    if (col < 7) sum += board[row][col + 1];
    return sum;
}