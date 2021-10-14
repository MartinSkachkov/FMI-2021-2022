#include <iostream>
using namespace std;

int main()
{//reverse digits
	int num;
	cout << "Enter a number: ";
	cin >> num; //7421

	int result = num % 10; //1
	num /= 10; //742
	result = result * 10 + num % 10; // 10 + 2 = 12
	num /= 10; //74
	result = result * 10 + num % 10; // 120 + 4 = 124
	num /= 10; // 7
	result = result * 10 + num; // 1240 + 7 = 1247
	cout << "Reversed number: " << result << endl;
	return 0;
}
