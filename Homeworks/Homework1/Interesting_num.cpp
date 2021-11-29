int main(){
  //Задача 3 - Интересно число
	//валидация на входа за интервала [a,b]
	int a, b;
	try
	{	
		cout << "Enter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;

		if (a>b)
		{
			throw "Invalid input! The interval should be [a,b]";
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
		return 0;
	}

	long interestingSum = 0; // сумата от всички интересни числа в [a,b]
	//проверяваме дали числото е интересно
	for (int currentNum = a; currentNum <= b; currentNum++) //'а' ни е началото на интервала, а 'b' е край
	{
		int currentNumCopy = currentNum;
		bool isInteresting = true;
		while (currentNumCopy != 0) //currNum = 94
		{
			int lastDigit = (currentNumCopy % 10) % 2; //(94 % 10)%2 --> (4)%2 --> 0
			int previousDigit = (currentNumCopy / 10 % 10) % 2; //(94 / 10 % 10)%2 --> (9 % 10)%2 --> (9)%2 --> 1;

			//случай за примерен интервал [5,8]
			if (currentNumCopy < 10) // currNum = 5
			{
				break; 
			}

			if (lastDigit == previousDigit)
			{
				isInteresting = false;
				break;
			}

			currentNumCopy /= 10; //9
		}

		if (isInteresting)
		{
			interestingSum += currentNum;
			cout << currentNum << ' ';
		}
	}

	cout <<endl<< "Sum of the interesting numbers is: " << interestingSum << endl;
	return 0;
}
