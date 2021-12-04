//Задача 2 - Баркодове
	int digits;
	do {
		cout << "The number of digits in the archive: ";
		std::cin >> digits;
	} while (digits <= 0 || digits % 8 != 0);
	
	int jamCounter = digits / 8, shipkaCounter = 0, blueberryCounter = 0, peachCounter = 0;

	cout << "Enter the digits: ";
	for (int i = 0; i < jamCounter; i++)
	{
		int jamBarcode = 0; // това ще са ни специфичните цифри, по които ще познаваме какъв вид е сладкото

		int countryCode;
		for (int i = 0; i < 3; i++)
		{
			cin >> countryCode;
		}
		for (int j = 0; j < 4; j++)
		{
			int jamDigits;
			cin >> jamDigits;
			jamBarcode = jamBarcode * 10 + jamDigits;
		}

		if (jamBarcode % 7 ==0)
		{
			blueberryCounter++;
		}
		if (jamBarcode % 13 ==0)
		{
			peachCounter++;
		}
		if (jamBarcode % 17 == 0)
		{
			shipkaCounter++;
		}

		int control;
		for (int i = 0; i < 1; i++)
		{
			cin >> control;
		}
	}

	cout << "Blueberries jam: " << blueberryCounter << endl;
	cout << "Peaches jam: " << peachCounter << endl;
	cout << "Shipka: " << shipkaCounter << endl;

	return 0;
