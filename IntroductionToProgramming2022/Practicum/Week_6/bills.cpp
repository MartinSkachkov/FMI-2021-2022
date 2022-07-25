#include <iostream>
#include <iomanip>
#define MAX_SIZE 100
#define EPS 0.0001
using namespace std;

void initArr(double* arr, unsigned int size) {
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void sort(double* arr, unsigned int size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printUncommon(double arr1[], double arr2[],
	int n1, int n2)
{

	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2) {

		// If not common, print smaller
		if (round(arr1[i]) < round(arr2[j])) {
			cout << arr1[i] << " ";
			i++;
			k++;
		}
		else if (round(arr2[j]) < round(arr1[i])) {
			cout << arr2[j] << " ";
			k++;
			j++;
		}

		// Skip common element
		else {
			i++;
			j++;
		}
	}

	// printing remaining elements
	while (i < n1) {
		cout << arr1[i] << " ";
		i++;
		k++;
	}
	while (j < n2) {
		cout << arr2[j] << " ";
		j++;
		k++;
	}
}

void printArr(double* arr, unsigned int size) {
	for (size_t i = 0; i < size; i++) {
		cout << fixed << setprecision(2) << arr[i] << ' ';
	}
}

int main() {
	double telephoneBills[MAX_SIZE];
	unsigned int billsSize;
	cout << "Bills number: ";
	cin >> billsSize;

	double paidBills[MAX_SIZE];
	unsigned int paidSize;
	cout << "Paid bills: ";
	cin >> paidSize;

	while (paidSize <= 1 || paidSize > billsSize || billsSize > 1000) {
		cout << "Invalid input! Enter again.";
		cin >> billsSize >> paidSize;
	}

	cout << "Bills:\n";
	initArr(telephoneBills, billsSize);
	cout << "Paid:\n";
	initArr(paidBills, paidSize);

	double toBePaid[MAX_SIZE];
	//cout << "Sorted bills: ";
	sort(telephoneBills, billsSize);
	//printArr(telephoneBills, billsSize);
	//cout << "Sorted paid: ";
	sort(paidBills, paidSize);
	//printArr(paidBills, paidSize);

	cout << "To be paid:\n";
	printUncommon(telephoneBills, paidBills, billsSize, paidSize);
	return 0;
}