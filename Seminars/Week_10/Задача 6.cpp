#include<iostream>
using namespace std;
#define MAX_SIZE_ROW 100
#define MAX_SIZE_COL 100

void PrintMatrix(int matrix[][MAX_SIZE_COL], int n, int m) {
	cout << "Current matrix:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void InitMatrix(int matrix[][MAX_SIZE_COL], int* n, int* m) {
	do {
		cout << "Enter n: ";
		cin >> *n;
		cout << "Enter m: ";
		cin >> *m;
	} while (*n < 1 || *n >16 || *m < 1 || *m>32);
	for (int i = 0; i < *n; i++) { // rows
		for (int j = 0; j < *m; j++) { // cols
			cin >> *(*(matrix + i) + j);
		}
	}
	cout << endl;
	PrintMatrix(matrix, *n, *m);
}

void UnderMainDiag(int matrix[][MAX_SIZE_COL], int n, int m) {
	cout << "Under the main diagonal: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << matrix[i][j]<<' ';
		}
		cout << endl;
	}
}

void AboveMainDiag(int matrix[][MAX_SIZE_COL], int n, int m) {
	cout << "Above the main diagonal: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i<j){ // с главния ще е i<=j
				cout << matrix[i][j]<<' ';
			}
		}
		cout << endl;
	}
}

void UnderSecondaryDiag(int matrix[][MAX_SIZE_COL], int n, int m) {
	cout<< "Under the secondary diagonal: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j > n-1) {
				cout << matrix[i][j]<<' ';
			}
		}
		cout << endl;
	}
}

void AboveSecondaryDiag(int matrix[][MAX_SIZE_COL], int n, int m) {
	cout << "Above the secondary diagonal: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j <= n - 1) {
				cout << matrix[i][j]<< ' ';
			}
		}
		cout << endl;
	}
}

void DeleteRowAndCol(int matrix[][MAX_SIZE_COL], int n, int m) {
	PrintMatrix(matrix, n, m);
	int row;
	cout << "Delete row: ";
	cin >> row;
	for (int i = row; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = matrix[i + 1][j];
		}
	}
	--n;
	PrintMatrix(matrix, n, m);

	int col;
	cout << "Delete col: ";
	cin >> col;
	for (int i = 0; i < n; i++) {
		for (int j = col; j < m; j++) {
			matrix[i][j] = matrix[i][j+1];
		}
	}
	--m;
	PrintMatrix(matrix, n, m);
}

int main() {
	int matrix[MAX_SIZE_ROW][MAX_SIZE_COL];
	int n, m;
	InitMatrix(matrix, &n, &m);
	UnderMainDiag(matrix, n, m);
	AboveMainDiag(matrix, n, m);
	UnderSecondaryDiag(matrix, n, m);
	AboveSecondaryDiag(matrix, n, m);
	DeleteRowAndCol(matrix, n, m);	
	return 0;
}

