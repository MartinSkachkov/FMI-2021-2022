include<iostream>
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
/*за nxn (3 <= n <= 32)*/
int size;
	do {
		cout << "Enter size: ";
		cin >> size;
	} while (size < 3 || size > 32);

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	printMatrix(matrix, size, size);
	int sumMatrixEven = MatrixSum(matrix, size, size);
  return 0;
}
