#include<iostream>
using namespace std;
#define MAX_SIZE_ROWS 100
#define MAX_SIZE_COLS 100

void printMatrix(int matrix[][MAX_SIZE_COLS], int rows, int cols) {
	cout << "-----------------------"<<endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j]<<' ';
		}
		cout << endl;
	}
}
int MatrixSum(int matrix[][MAX_SIZE_COLS], int rows, int cols) {
	int sumEven = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] % 2 == 0)
			{
				sumEven += matrix[i][j];
			}
		}
	}
	return sumEven;
}

int main(){
	//матрица nxm
	int matrix[MAX_SIZE_ROWS][MAX_SIZE_COLS];
	int rows, cols;
	do{
	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter cols: ";
	cin >> cols;
	} while (rows < 1 || cols < 1);

	//matrix nxm, ако е nxn rows == cols
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}
	
	printMatrix(matrix, rows, cols);
	int sumMatrixEven = MatrixSum(matrix, rows,cols);
	cout << "The sum of the even elements in the matrix is: "<< sumMatrixEven;
