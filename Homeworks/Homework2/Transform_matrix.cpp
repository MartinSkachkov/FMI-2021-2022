#include <iostream>
using namespace std;

void PrintMatrix(int** matrix, int n, int m)
{
	for (int rows = 0; rows < n; rows++)
	{
		for (int cols = 0; cols < m; cols++)
		{
			cout << matrix[rows][cols] << ' ';
		}
		cout << endl;
	}
}

void DeleteMemory(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int** TransformMatrix(int** matrix_a, int** matrix_b, int* n1, int* m1, int n2, int m2)
{
	int rows = *n1, cols = *m1;
	if (n2 < *n1) // броят на редовете ѝ N1 се намалява на N2
	{
		rows = n2;
	}

	if (m2 < *m1) // броят на колоните ѝ M1 се намалява на M2
	{
		cols = m2;
	}

	int** temp_matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		temp_matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			temp_matrix[i] = matrix_a[i];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix_a[i][j] == matrix_b[i][j])
			{
				continue;
			}
			if (matrix_a[i][j] < matrix_b[i][j])
			{
				matrix_a[i][j] = matrix_b[i][j];
			}
			if (matrix_a[i][j] > matrix_b[i][j])
			{
				matrix_a[i][j] *= -1;
			}
		}
	}

	return temp_matrix;
}

int main() {
	int n1, m1, n2, m2;
	do {
		cout << "N1: "; //rows
		cin >> n1;
		cout << "M1: "; //cols
		cin >> m1;
		cout << "N2: ";
		cin >> n2;
		cout << "M2: ";
		cin >> m2;
	} while (n1 < 0 || m1 < 0 || n2 < 0 || m2 < 0);

	int** matrix_a = new int* [n1];
	int** matrix_b = new int* [n2];

	//initializing the matrices
	cout << "Enter matrix A: " << endl;
	for (int rows = 0; rows < n1; rows++)
	{
		matrix_a[rows] = new int[m1];
		for (int cols = 0; cols < m1; cols++)
		{
			cin >> matrix_a[rows][cols];
		}
	}

	cout << "Enter matrix B: " << endl;
	for (int rows = 0; rows < n2; rows++)
	{
		matrix_b[rows] = new int[m2];
		for (int cols = 0; cols < m2; cols++)
		{
			cin >> matrix_b[rows][cols];
		}
	}
	//printing the matrices
	cout << "Matrix A: " << endl;
	PrintMatrix(matrix_a, n1, m1);
	cout << "Matrix B: " << endl;
	PrintMatrix(matrix_b, n2, m2);

	//Transforming the matrix
	matrix_a = TransformMatrix(matrix_a, matrix_b, &n1, &m1, n2, m2);
	cout << "Transformed matrix: " << endl;
	PrintMatrix(matrix_a, n1, m1);

	//deleting the memory
	DeleteMemory(matrix_a, n1);
	DeleteMemory(matrix_b, n2);

	return 0;
}
