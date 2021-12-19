#include<iostream>
using namespace std;
#define MAX_SIZE 100

void MatrixInit(int matrix[][MAX_SIZE], int *size) {
	do
	{
		cout << "Enter size: ";
		cin >> *size;
	} while (*size < 3 || *size>32);

	for (int rows = 0; rows < *size; rows++) {
		for (int cols = 0; cols < *size; cols++){
			cin >> matrix[rows][cols];
		}
	}
}

int MaxRow(int matrix[][MAX_SIZE], int size) {
	int maxSumRow = INT32_MIN, currentRow;
	for(int rows = 0; rows < size; ++rows) {
		int sum = 0;
		for (int cols = 0; cols < size; ++cols) {
			sum += matrix[rows][cols];
		}
		if (sum> maxSumRow)
		{
			maxSumRow = sum;
			currentRow = rows;
		}
	}
	return currentRow;
}

int MaxCol(int matrix[][MAX_SIZE], int size) {
	int currentCol, maxSumCol = INT32_MIN;
	for (int cols = 0; cols < size; ++cols) {
		int sum = 0;
		for (int rows = 0; rows < size; ++rows) {
			sum += matrix[rows][cols];
		}
		if (sum > maxSumCol) {
			maxSumCol = sum;
			currentCol = cols;
		}
	}
	return currentCol;
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int size;
	MatrixInit(matrix, &size);
	cout << "Max row: " << MaxRow(matrix, size)<<endl;
	cout << "Max col: " << MaxCol(matrix, size)<<endl;
	return 0;
}
	
