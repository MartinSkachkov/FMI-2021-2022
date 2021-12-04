#define EPSILON 0.0001 // константа малко отклонение за зад.0

double area(double x1, double y1, double x2, double y2, double x3, double y3) { //функция която ще ни смята лицата на триъгълниците за зад.0
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0); // това, което е вътре в abs ни смята дължините на страните на триъгълника и
	// вече разделено на 2.0 дава лицето
}

// функция, проверяваща дали точка е в триъгълник за зад.0
bool isInside(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) {
	double main_area = area(x1,y1,x2,y2,x3,y3); // лицето на основния триъгълник
	// лицата, на които точката, въвдена от потребителя, ще разбие основния триъгълник
	double area1 = area(x, y, x2, y2, x3, y3);
	double area2 = area(x1, y1, x, y, x3, y3);
	double area3 = area(x1, y1, x2, y2, x, y);

	return(abs(main_area - area1 - area2 - area3) < EPSILON);
}
int main()
{
	//Задача 0 - Декартова координатна система
	double x, y, rounded_x, rounded_y, m;//координатите на нашата точка

	cout << "Enter x: ";
	cin >> x;
	rounded_x = round(x * 1000.0) / 1000.0;
	cout << "Enter y: ";
	cin >> y;
	rounded_y = round(y * 1000.0) / 1000.0;
	double on_the_line= x / y;
	if (on_the_line == 1 || on_the_line == -1 || abs(0 - x)< EPSILON || (round(sqrt(8) * 1000.0) / 1000.0-x)<EPSILON)
	{
		cout << "it's on the line";
		return 0;
	}

	//Rectangle
	if ((x > -2 && x < 2) && (y < -6 && y > -7))
	{
		cout << "gray area";
	}

	//Circle
	if (pow(x, 2) + pow(y, 2) < 16)
	{

		//purple
		double B_x = round(sqrt(8) * 1000.0) / 1000.0; //координатите на точка B
		double B_y = B_x;
		bool purple = false;
		if (x > B_x) {
			cout << "purple area";
			purple = true;
		}
		//white(a.k.a outside the areas)
		bool white = false;
		if (x < round(-sqrt(8) * 1000.0) / 1000.0) {
			cout << "not in any area";
			white = true;
		}
		//yellow triangle
		bool yellow = false;
		
		if (isInside(0, 0, B_x, B_y, (round(sqrt(8) * 1000.0) / 1000.0), 0, x, y))
		{
			cout << "yellow area";
			yellow = true;
		}
		//green area
		if ((y > 0 && y < 4) && (x > 0 && x < 4) && purple == false && yellow == false && white == false)
		{
			cout << "green area";
		}
		//yellow area
		if ((y < 0 && y > -4) && (x > 0 && x < 4) && purple == false)
		{
			cout << "yellow area";
		}
		//pink triangle
		double D_x = round(-sqrt(8) * 1000.0) / 1000.0; //координатите на точка D
		double D_y = round(sqrt(8) * 1000.0) / 1000.0;
		double C_x = round(-sqrt(8) * 1000.0) / 1000.0; //координатите на точка C
		double C_y = C_x;
		bool pink = false;

		if (isInside(0,0,D_x,D_y,C_x,C_y,x,y))
		{
			cout << "pink area";
			pink = true;
		}
		//red area
		if ((x> round(-sqrt(8) * 1000.0) / 1000.0 && x<0)&&pink == false)
		{
			cout << "red area";
		}
		//cyan
		if ((x > round(-sqrt(8) * 1000.0) / 1000.0 && x < 0) && (y < 0 && y > -4)&&pink == false)
		{
			cout << "light blue area";
		}

	}
