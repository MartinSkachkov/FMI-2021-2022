#include <iostream>
using namespace std;
#define MAX_SIZE 1024

void initArr(int* arr, unsigned int size) {
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
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

	for (size_t i = 0; i < firstLen; i++) {
		bool flag = true;
		for (size_t j = 0; j < secondLen; j++) {
			if (firstArr[i] == secondArr[j]) {
				flag = false;
				break;
			}
		}
		if (flag == true && firstArr[i] % 3 != 0) {
			cout << firstArr[i] << ' ';
		}
	}

	return 0;
}