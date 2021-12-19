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

bool isPrime(int number) {
	for (int i = 2; i <= number/2; i++){ //sqrt(2)
		if (number %i ==0){ //условие за непросто число
			return false;
		}
	}
	return true;
}

int CountOfPrime(int matrix[][MAX_SIZE], int size) {
	int counter = 0;
	for (int rows = 0; rows < size; rows++){
		for (int cols = 0; cols < size; cols++) { //има и др начин cols = rows и в if махаме rows <= cols
			if (rows <= cols && isPrime(matrix[rows][cols])) {
				counter++;
			}
		}
	}
	return counter;
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int size;
	MatrixInit(matrix, &size);
	cout << "Prime numbers: " << CountOfPrime(matrix, size);
}
