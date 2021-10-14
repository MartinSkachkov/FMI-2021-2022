#include <iostream>
using namespace std;

int main()
{//shopping calculator
	int apple_cnt, banana_cnt, orange_cnt;
	double apple_price, banana_price, orange_price;

	cout << "Apples: ";
	cin >> apple_cnt >> apple_price;
	double totalA = apple_cnt * apple_price;

	cout << "Bananas: ";
	cin >> banana_cnt >> banana_price;
	double totalB = banana_cnt * banana_price;

	cout << "Oranges: ";
	cin >> orange_cnt >> orange_price;
	double totalO = orange_cnt * orange_price;

	cout << "Your order is: apples for " << totalA;
	cout << ", oranges for " << totalO;
	cout << " and bananas for " << totalB << "." << endl;
	cout << "Total: " << totalA + totalB + totalO;
}
