# Задачи

Допълнително упражнение преди контролно 2.

## Масиви

> Задача 1 (за загрявка)

Да се дефинира функция, която преобразува положително цяло число в съответния му символен низ и връща така построения символен низ.
**Забележка**: Да се използва динамична памет!

```cpp
char* stringRepresentation(int number) {
    // alloc mem
    size_t strLen = numlen(number);
    char* str = new char[strLen + 1];
    str[strLen] = 0;

    while (number != 0) {
        // int to str -> '8' +'0';
        str[strLen - 1] = char(number % 10) + '0';  // saving back to start
        number /= 10;
        strLen--;
    }
    return str;
}
```

> Задача 2

Да се реализира функция split със следната сигнатура:

```c++
char** split(char* source, char delimiter, int& size);
```

Идеята на тази функция е да раздели символния низ **source** на поднизове спрямо разделителя **delimiter**.

Пример:

    Вход:
    "This is the most used function in the world!" ' '

    Изход:
    ["This", "is", "the", "most", "used", "function", "in", "the", "world!"]

> Задача 3

Дадена е квадратна матрица с размери nxn, n ∈ [1; 10], която описва лабиринт. Стойност 0 в дадена клетка означава **стена**, стойност 1 означава **свободно място за движение**. Даден е низ съдържащ само буквите E(east), W(west), N(north) и S(south), които указват едностъпкови придвижвания в съответните географски посоки. Да се напише функция, която проверява дали даден низ е валиден път от някоя проходима клетка в лабиринта до долния десен ъгъл на лабиринта.

Пример:

    Вход 1:
    4
    0 1 1 1
    0 1 1 1
    0 1 0 0
    0 1 1 1
    EESWWSSEE

    Изход:
    true

    Вход 2:
    4
    0 1 1 1
    0 1 1 1
    0 1 0 0
    0 1 1 1
    WWSEEWWSSEE

    Изход:
    true

    Вход 3:
    4
    0 1 1 1
    0 1 1 1
    0 0 0 0
    0 1 1 1
    EESWWSSEE

    Изход:
    false

    Вход 4:
    4
    0 1 1 1
    0 1 1 1
    0 0 0 0
    0 1 1 1
    WWSEEWWSSEE

    Изход:
    false

> Задача 4

Дадена е квадратна матрица от естествени числа с размерност n×n,n∈[2;20]. Да се напише функция, която сортира редовете на матрицата в низходящ ред според сумата на цифрите във всеки от елементите.

```cpp
void BubbleSort(int* rows, const size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - 1 - i; j++) {
            // if the sum of the digits of the curr number is bigger than the
            // next then swap the real numbers
            if (sumDigits(rows[j]) > sumDigits(rows[j + 1])) {
                swap(rows[j], rows[j + 1]);
            }
        }
    }
}

void sortRows(int** matrix, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        BubbleSort(matrix[i], n);
    }
}
```

> Задача 5

Да се напише функция, която получава като параметри матрица от числа във вид на двумерен масив. Функцията да извежда на екрана сумата на числата в редовете и колоните, в които броят на елементите, удовлетворяващи условието да са четни числа, по-малки от 6, е максимален за матрицата.

Пример:
Нека е дадена матрицата
1 2 2 4
3 4 4 5
3 4 6 7

Функцията трябва да извежда на екрана числото 19, което е сумата на реда 1+2+2+4 и
на колоната 2+4+4, тъй като и в двете има по три числа, удовлетворяващи предиката.

## Рекурсия

> Задача 1

Да се дефинира рекурсивна функция, която вмъква елемент **x**, въведен от клавиатурата в **сортиран** масив. **Забележка:** Функцията да заделя памет за по-голям масив, като променя първоначално подадения такъв.

```cpp
void addElement(int* arr, size_t size, int x) {
    // if we are at the begining place it first
    if (size == 0) {
        arr[0] = x;
        return;
    }
    // room for improvement with the resize func
    if (size >= capacity) {
        resize(arr, capacity);
    }
    if (arr[size - 1] > x) {
        arr[size] = arr[size - 1];  // shift them by one position
        addElement(arr, size - 1, x);
    } else {
        arr[size] = x;
        return;
    }
}
```

> Задача 2

Да се дефинира рекурсивна функция, която сравнява лексикографски два символни низа.

```cpp
int strcmpRecursion(char* str1, char* str2) {
    if (*str1 > *str2) {
        return 1;
    }
    if (*str1 < *str2) {
        return -1;
    }
    if (*str1 == 0) {
        return 0;
    }
    return strcmpRecursion(str1 + 1, str2 + 1);
}
```

> Задача 3

Даден е лабиринт под формата на матрица NxM, където свободно квадратче се отбелязва с `'.'` , а стена с - `'#'`. Намерете има ли път от квадратче с координати (0, 0) до квадратче (N - 1, M - 1), движейки се в четирите основни посоки.

Пример:

    Вход:
    4 4
    . # # .
    . . # #
    . # . .
    . . . .

    Изход:
    Yes

    Вход:
    3 5
    . # # . .
    # . # # #
    . . . . .

    Изход:
    No

```cpp
bool safePosition(char** maze, size_t currRow, size_t currCol, size_t destRow,
                  size_t destCol) {
    // if we are within the bounds of the maze and the current position is '.'
    // everything is ok
    if ((currRow >= 0 && currRow <= destRow) &&
        (currCol >= 0 && currCol <= destCol) &&
        (maze[currRow][currCol] == '.')) {
        return true;
    }
    return false;
}

bool findPath(char** maze, bool** path, size_t currRow, size_t currCol,
              size_t destRow, size_t destCol) {
    // base case
    if (currRow == destRow && currCol == destCol) {
        path[currRow][currCol] = 1;
        return true;  // found a path to the end
    }

    // if we are not at the end
    if (safePosition(maze, currRow, currCol, destRow, destCol) == true) {
        if (path[currRow][currCol] == 1) {
            return false;
        }
        path[currRow][currCol] = 1;

        if (findPath(maze, path, currRow + 1, currCol, destRow, destCol) ==
            true) {
            return true;
        }
        if (findPath(maze, path, currRow - 1, currCol, destRow, destCol) ==
            true) {
            return true;
        }
        if (findPath(maze, path, currRow, currCol + 1, destRow, destCol) ==
            true) {
            return true;
        }
        if (findPath(maze, path, currRow, currCol - 1, destRow, destCol) ==
            true) {
            return true;
        }
        path[currRow][currCol] = 0;
        return false;
    }
    return false;
}
```

> Задача 4:

Да се напише рекурсивна функция, която намира числото xy, по въведени сбор x+y от цифрите x и y и разликата между числата yx - xy.
Пример:
Вход: Сбор x + y = 12; Разлика yx - xy = 36.
Изход: 48

```cpp
int concatDigits(int x, int y) {
    int yCopy = y;
    do {
        x *= 10;
        yCopy /= 10;
    } while (yCopy);

    return x + y;
}

int findNum(int sum, int difference, int x, int y) {
    // base case
    if (((x + y) == sum) &&
        ((concatDigits(y, x) - concatDigits(x, y)) == difference)) {
        return concatDigits(x, y);
    }
    y++;
    x = sum - y;
    return findNum(sum, difference, x, y);
}
```
