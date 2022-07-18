	int number;
	std::cin >> number;

	std::cout << std::boolalpha << (((number % 10 == 7) + (number / 10 % 10 == 7) + (number / 100 % 10 == 7)) % 2 == 0);