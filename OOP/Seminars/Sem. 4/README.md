# Член-функции. Конструктори и деструктор. Модификатори за достъп. Капсулация.

## Член-функции.
Член-функциите са функции, които работят с член-данните на обекта от дадена структура.
 ```c++
struct Point
{
	int x;
	int y;
};
bool isInFirstQuadrant(const Point& p) // не е член-функция и ни трябва обект за дотъп до член данните
{
	return p.x >= 0 && p.y >= 0;
}

void revert(Point& p)
{
	p.x = -p.x;
	p.y = -p.y;
}

int main()
{
	Point p1 = {3, 4};
	Point p2 = {-9, 8};
	cout << isInFirstQuadrant(p1) << endl;
	cout << isInFirstQuadrant(p2) << endl;
}
 ```
 
 Може функцията да бъде член-функция:
 ```c++
struct Point
{

	int x;
	int y

	bool isInFirstQuadrant() const // член-функция и не ни трябва обект за достъп до член данните
    //is..(Point* this)
	{
		return x >= 0 && y >= 0;
	}
	
	void revert()
	{
		x = -x;
		y = -y;
	}
};

int main()
{
	Point p1 = {3, 4};
	Point p2 = {-9, 8};
	cout << p1.isInFirstQuadrant() << endl; // достъпваме член-функцията чрез обект is..(&p1)
	cout << p2.isInFirstQuadrant() << endl;
}
 ```
#  
**Член-функциите**:

 - Работят с член-данните на класа.
 -  Извикват се с обект на класа
 
 - Компилаторът преобразува всяка **член-функция** на дадена структура в
   обикновена функция с уникално име и един допълнителен параметър
   –**указател към обекта**.

**Константни член-функции**:

 - Не променят член-данните на структурата.
 -  Оказва се чрез записването на ключовата  дума **const** в декларацията и в края на заглавието в дефиницията им
 -  Могат да се извикват от константни обекти.
## Конструктори и деструктор.

**Жизнен цикъл на обект**:
 - Създаване на обект в даден scope – заделя се памет и член-данните се инициализират.
 - Достига се до края на скоупа(област).
 - Обектът и паметта, която е асоциирана с него се разрушава.

**Конструктор**:
 - Извиква се веднъж - при създаването на обекта.
 - Не се оказва експлицитно тип на връщане (връща констатна референция).
 - Има същото име като класа.
 
 **Деструктор**:
 - Извиква се веднъж - при изтриването на обекта.
 - Не се оказва експлицитно тип на връщане.
 - Има същото име като класа със симовла '~' в началото.

 ```c++

#include <iostream>

using namespace std;


struct Test 
{
  Test()
  {
  	cout << "Object is created" <<endl;
  }
  
 ~Test()
  {
  	cout << "Object is destroyed" <<endl;
  }
  int a;
  int b;
};

int main()
{
	while ()
	{
		Test t;// Object is created 
		if ()
		{
			Test t2; // Object is created 

		}// Object is destroyed (t2)

	}//Object is destroyed (t)
}

 ```
 ## Конструктори и деструктор при влагане на обекти.
 
  ```c++
#include <iostream>
#include <iomanip>

using namespace std;

struct A
{
	A()
	{
		std::cout << "Constructor(default) of A" << std::endl;
	}

	~A()
	{
		std::cout << "Destructor of A" << std::endl;
	}
};

struct B
{
	B()
	{
		std::cout << "Constructor(default) of B" << std::endl;
	}

	~B()
	{
		std::cout << "Destructor of B" << std::endl;
	}
};

struct C
{
	C()
	{
		std::cout << "Constructor(default) of C" << std::endl;
	}

	~C()
	{
		std::cout << "Destructor of C" << std::endl;
	}
};

struct X
{
	A first;
	B second;
	C obejectsArray[3];

	X()
	{ //calls Constructor(default) of A, Constructor(default) of B, Constructor(default) of C" (x3)
		std::cout << "Constructor of X" << std::endl;
	}
	~X()
	{
		std::cout << "Destructor of X" << std::endl;
	} //calls Destructor of C" (x3) , Destructor of B, Destructor of A

};

int main()
{
	X  obj; //Constructor of X
} // Destructor of X
 ```