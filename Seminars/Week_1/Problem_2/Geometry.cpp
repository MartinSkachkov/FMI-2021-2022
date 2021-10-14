#include <iostream>
using namespace std;

int main()
{//calculate geometry
	double input,s, p,t,c; // input>0
	cout << "Enter input: ";
	cin >> input;

	if (input > 0)
	{
		t = input * input * 1.372;
		c = 3.14 * input * input;
		s = input * input;
		p = 3 * input;
		cout << "Triangle: " << t << " " << p << endl;
		cout << "Circle: " << c << " " << p << endl;
		cout << "Square: " << s << " " << p << endl;
		return 0;
	}
} 
