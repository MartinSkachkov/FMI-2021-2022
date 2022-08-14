#include <iostream>
using namespace std;

int main() {
	unsigned int histogram[26] = { 0 };
	char arr[5] = { 0 };
	cin.getline(arr, 5);

	for (size_t i = 0; i < 5; i++){
		histogram[arr[i] - 'a']++;
	}
	for (size_t i = 0; i < 26; i++)
	{
		if (histogram[i] > 0) {
			cout << char('a' + i) << "->" << histogram[i] << '\n';
		}
	}

	return 0;
}
