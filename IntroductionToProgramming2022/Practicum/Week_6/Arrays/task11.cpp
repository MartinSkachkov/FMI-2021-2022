#include <iostream>
#define MAX_SIZE 100
using namespace std;

void initArr(int* arr, unsigned int size) {
	cout << "Arr init: ";
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

int* VectorMultiplication(int vector1[], unsigned int size1, int vector2[], unsigned int size2) {
	int* result = new int[size1]; // if it was statically allocated then the function would have deleted the 
	//memory after the end of it and would print random values
	//with dynamic allocation we control the memory :D
	for (size_t i = 0; i < size1; i++) {
		result[i] = vector1[i] * vector2[i];
	}
	return result; //we return the name of the array which is pointer to the first element
}


void printArr(int* arr, unsigned int size) {
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
}

int main() {
	int vector1[MAX_SIZE], vector2[MAX_SIZE];
	int size1, size2;
	
	do{
	cout << "Size1: ";
	cin >> size1;

	cout << "Size2: ";
	cin >> size2;
	} while (size1 != size2);

	initArr(vector1, size1);
	initArr(vector2, size2);

	int* vectorMultiplication = VectorMultiplication(vector1, size1, vector2, size2);

	printArr(vectorMultiplication, size1);
	int scalarProduct = 0;
	for (size_t i = 0; i < size1; i++) {
		scalarProduct += vectorMultiplication[i];
	}
	cout << "\nScalar product: " << scalarProduct;

	delete[] vectorMultiplication;
	return 0;
}