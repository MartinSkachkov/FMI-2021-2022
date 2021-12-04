  int x;
	cout << "Enter a number: ";
	std::cin >> x;
	int result = x; // f1(x) = x

	for (int k = 2; k <= 35; ++k) { 
		if (result % 2 == 0) {
			result = result / 2;
		}
		else {
			result = 3 * result + 1;
		}
	}

	cout << result << endl;
