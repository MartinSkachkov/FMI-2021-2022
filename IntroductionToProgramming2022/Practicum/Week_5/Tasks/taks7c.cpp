#include <iostream>
using namespace std;
#define MAX_SIZE 1024

void initArr(int* arr, unsigned int size) {
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void bubbleSort(int* arr, unsigned int size) {
	int temp = 0;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main() {
	int firstArr[MAX_SIZE];
	int secondArr[MAX_SIZE];
	unsigned int firstLen, secondLen;

	cout << "First length: ";
	cin >> firstLen;
	cout << "Second length: ";
	cin >> secondLen;

	initArr(firstArr, firstLen);
	initArr(secondArr, secondLen);

	bubbleSort(firstArr, firstLen);
	bubbleSort(secondArr, secondLen);

	int newArr[2*MAX_SIZE];
	unsigned int newLen = firstLen + secondLen;
	int index1 = 0, index2 = 0,
		index3 = 0;
	while (index1 < firstLen && index2 < secondLen) {
		if (firstArr[index1] > secondArr[index2]) {
			newArr[index3++] = secondArr[index2++];
		}
		else{
			newArr[index3++] = firstArr[index1++];
		}
	}

	while (index1 < firstLen) {
		newArr[index3++] = firstArr[index1++];
	}

	while (index2 < secondLen) {
		newArr[index3++] = secondArr[index2++];
	}

	for (size_t i = 0; i < newLen; i++) {
		cout << newArr[i] << ' ';
	}
	return 0;
}