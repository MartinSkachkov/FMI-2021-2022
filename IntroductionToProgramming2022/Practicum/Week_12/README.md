# Задачи 
### :christmas_tree: Christmas edition :gift:

## Динамично заделяне на памет
```cpp
// C++ program to handle memory failure
// when very large memory is allocated
#include <iostream>
using namespace std;

// Drive Code
int main()
{
	// Allocate huge amount of memory
	long MEMORY_SIZE = 0x7fffffff;

	// Allocate memory dynamically
	// using "new" with "nothrow"
	// version of new
	char* addr = new (std::nothrow) char[MEMORY_SIZE];
    //if it has't allocated memory correctly it return a NULL-ptr , otherwise it returns an adress in memory

	// Check if addr is having
	// proper address or not
	if (addr) {

		cout << "Memory is allocated"
			<< " Successfully" << endl;
	}
	else {

		// This part will be executed if
		// large memory is allocated and
		// failure occurs
		cout << "Memory allocation"
			<< " fails" << endl;
	}

	return 0;
}
```

> :cookie: Задача 1 

Даден е символен низ с произволна дължина. Да се напише функция, която записва в масив от цели числа всички числа, които могат да се прочетат
в низа. Число е последователност от символи, които представляват цифри. Не се допуска да има водещ знак (+/-). Използвайте динамично заделяне на памет за символния низ.
<details>
<summary>
<b>Пример</b>
</summary>


```
Вход: "Рецепта за джинджифилови коледни бисквитки: 500гр. брашно, 125гр. масло, 10гр. хлебна сода, 10гр. канела, 1 яйце, 150гр. мед, 20гр. джинджифил. Продуктите се смесват, оформят се бисквитки и се пекат на загрята фурна на 180 градуса за 7-8 минути."
Резултат: масив с елементи [500, 125, 10, 10, 1, 150, 20, 180, 7, 8].
```

</details>



> :candy: Задача 2

Майката на Мими купила за Коледа кутия шоколадови бонбони (5х5) с бял (W), млечен (M) и черен (D) шоколад. За беда Мими изтървала кутията и част от бонбоните се разпилели. Тя започнала да ги подрежда обратно по следните правила - кутията се дозапълва с разпилетите бонбони, като кутията се приема за подредена, ако:

	1. броят на бонбоните от всеки вид на всеки ред е равен на броя на бонбоните от всеки вид в същия ред в първоначалната подредба

или

	2. подредбата на Мими е точно копие на първоначалната подредба

Да се състави функция, която проверява дали дадена кутия е подредена по подадени първоначалната кутия и новоподредената кутия. Използвайте динамично заделяне на памет.
<details>
<summary>
<b>Пример</b>
</summary>


```
Вход 1: 
W W D M W
D W M W D
M D W D W
M M M D M
M D W W W

D W M W W
D D M W W
M W W D D
M M M M D
W W W D M

Изход 1:
Box is fixed.

Вход 2:
W W D M M
D W M W D
M D W D W
M M M D M
M D W W W

D W M W W
D D M W W
M W W D D
M M M M D
W W W D M

Изход 2:
Box is not fixed. 
```

</details>

### *За всички масиви заделянето на памет да се направи динамично!*
задачите са решени в Week_11\Tasks.
> Задача 3

Дадена е целочислена матрица с размерност nxm (n, m e [1; 10]). Да се напише програма, която проверява дали съществува елемент, който е равен на сумата от съседите си. Всеки елемент има до 8 съседа.


> Задача 4

Да се напише програма, която умножава матриците A<sub>nxm</sub> и B<sub>mxk</sub> (1 <= n <= 20, 1<= m <= 30, 1 <= k <= 40).

> Задача 5

Квадратна матрица A с размерност n (1 <= n <= 20) е триъгълна, ако за елементите ѝ е в сила: a<sub>i, j</sub> = 0, ако i > j и a<sub>i, j</sub> != 0, ако i <= j или a<sub>i, j</sub> = 0, ако i < j и a<sub>i, j</sub> != 0, ако i >= j, за i, j = 1, 2, ... n. Да се напише програма, която определя дали А е триъгълна.

> Задача 6

Да се напише програма, която определя дали квадратна матрица A с размерност (1 <= n <= 20) е магически квадрат, т.е. такава, че сумата от елементите от всички редове, стълбове и двата диагонала е еднаква.

    Вход:
    3 3
    2 7 6
    9 5 1
    4 3 8

    Изход:
    true

## Рекурсия 

> Задача 1

Да се напише рекурсивна функция, която представя число от десетична в двоична бройна система.

```cpp
size_t toBinary(int decimal) {
    return decimal == 0 ? 0 : decimal % 2 + 10 * toBinary(decimal / 2);
}
```

> Задача 2

Въведете числата x от тип double и n от тип int. Да се напише програма, която намира стойността на израза чрез рекурсия:
sum = ( ...(((x + 2)x + 3)x + 4)x +... + (n-1))x + n;

```cpp
int sum(double x, int n) {
    if (n == 2) {
        return x + 2;
    } else {
        return n + x * sum(x, n-1);
    }
}
```

> Задача 3

Дадени са естествените числа n и k, където 1 ≤ k ≤ n. Да се дефинира рекурсивна функция, която намира сумата на естествените числа от 1 до n със стъпка k. 

<details>
<summary>
<b>Пример</b>
</summary>


```
при n = 15 и k = 3: 1 + 4 + 7 + 10 + 13 = 35
```

</details>

```cpp
int sum(int n, int offset, int base) {
    if (base >= n) {
        return 0;
    }
    return base + sum(n, offset, base + offset);
}
```

> Задача 4

Да се напише функция, която пресмята 1 + 1/2 + 1/3 + ... + 1/n.

```cpp
double calc(size_t n) {
    if (n == 1) {
        return 1;
    }
    return (1.0 / n) + calc(n - 1);
}
```

> Задача 5

Да се напише рекурсивна функция, която намира най-малката цифра в число.

```cpp
int smallestDigit(int num, int digit) {
    if (num == 0) {
        return digit;
    }
    if (digit > num % 10) {
        digit = num % 10;
    }
    smallestDigit(num / 10, digit);
}
```

> Задача 6

Да се напише рекурсивна функция, която намира сумата на цифрите в дадено число.

```cpp
int sumOfDigit(int num, int sum) {
    if (num == 0) {
        return sum;
    }
    sum += num % 10;
    sumOfDigit(num / 10, sum);
}
```