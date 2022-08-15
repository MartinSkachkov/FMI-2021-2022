#include <iostream>
#define MAX_LEN 101
using namespace std;

size_t strlen(char* str) {
	size_t len = 0;
	while (*str != 0) {
		str++;
		len++;
	}
	return len;
}

void bubbleSort(int* arr, size_t n) {
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int strToNum(char* strNum) {
	size_t strNumLen = strlen(strNum);
	int num = 0;

	for (size_t i = 0; i < strNumLen; i++) {
		num = 10 * (num + (strNum[i] - '0'));
	}
	num /= 10;
	return num;
}

int* process(char** str, size_t n) {
	int* nums = new int[n];

	for (size_t i = 0; i < n; i++) {
		int num = strToNum(str[i]);
		nums[i] = num;
	}
	bubbleSort(nums, n);

	return nums;
}

int main() {
	size_t n;
	cout << "n: ";
	cin >> n;
	if (n <= 0) {
		cout << "n can't be zero!";
		return -1;
	}

	char** str = new (nothrow) char* [n];
	if (!str) {
		cout << "could not allocate memory!";
		return -1;
	}

	cin.ignore();
	for (size_t i = 0; i < n; i++) {
		str[i] = new char[MAX_LEN];
		if (!str[i]) {
			cout << "could not allocate memory!";
			return -1;
		}
		cout << "str: ";
		cin.getline(str[i], MAX_LEN);
	}

	int* nums = nullptr;
	nums = process(str, n);

	for (size_t i = 0; i < n; i++) {
		delete[] str[i];
		cout << nums[i] << ' ';
	}
	delete[] nums;
	return 0;
}
