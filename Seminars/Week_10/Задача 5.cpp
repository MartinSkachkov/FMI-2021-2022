#include<iostream>
using namespace std;
#define MAX_SIZE_ROW 100
#define MAX_SIZE_COL 100

void PrintMatrix(int matrix[][MAX_SIZE_COL], int n, int m) {
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
	PrintMatrix(matrix, *n, *m);
}


void DeleteRow(int matrix[][MAX_SIZE_COL], int n, int m) {
	int k;
	cout << "Which row to delete: ";
	cin >> k;
	for (int i = k; i < n; i++){
		for (int j = 0; j < m; j++) {
			matrix[i][j] = matrix[i + 1][j];
		}
	}
	--n;
	PrintMatrix(matrix, n, m);
}


int main() {
	int matrix[MAX_SIZE_ROW][MAX_SIZE_COL];
	int n, m;
	InitMatrix(matrix, &n, &m);
	DeleteRow(matrix, n, m);
	return 0;
}

