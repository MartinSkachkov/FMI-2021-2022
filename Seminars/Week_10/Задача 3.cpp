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

bool isOne(int number) {
	while (number != 0) {
		if (number%10 == 1)
		{
			return true;
		}
		number /= 10;
	}
	return false;
}

int MultiplicationOne(int matrix[][MAX_SIZE], int size) {
	int multi = 1;
	for (int rows = 0; rows < size; rows++){
		for (int cols = 0; cols < size; cols++) { 
			if (rows + cols >= size && isOne(*(*(matrix+rows)+cols))) { //може също rows + cols > size - 1
				multi *= *(*(matrix+rows)+cols);
			}
		}
	}
	return multi;
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int size;
	MatrixInit(matrix, &size);
	cout << "Multi: " << MultiplicationOne(matrix,size)<<endl;
}
