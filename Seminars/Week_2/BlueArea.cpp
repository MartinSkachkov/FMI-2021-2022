#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int A;
	cout<<"Въведете дължината на страната А(по условие др. е 2А): ";
	cin>>A;
	
	int areaRectangle = A*(2*A);
	int areaCircle = (pow(A,2)*3.14)/2;
	int result = areaRectangle - areaCircle;
	
	cout<<result;
}
