# Задачи

## Рекурсия

> Задача 1.

Дадена е квадратна мрежа от клетки, всяка от които е празна или запълнена. Запълнените клетки, които са свързани, т.е. имат съседни в хоризонтално, вертикално или диагонално направление, образуват област. Да се напише програма, която намира броя на областите и размера на всяка област в брой клетки.

> Задача 2.

Дадени са n града, (n е естествено число, 1 <= n <= 20) и целочислена матрица Anxn, такава, чe:

    - aij = 1, ако има пряк път от град i до град j и
	- aij = 0 в противен случай.
Да се напише булева функция hasFixedWay(int** arr, int n, int i, int j, int p), която проверява дали съществува път от град i до град j с дължина р.

> Задача 3.

Дадена е квадратна матрица с размери nxn, n която описва лабиринт. Стойност 0 в дадена клетка означава „стена“, стойност 1 означа „свободно място за движение“. Даден е низ съдържащ само буквите E(east), W(west), N(north) и S(south), които указват едностъпкови придвижвания в съответните географски посоки. Да се напише функция, която проверява дали даденият низ е валиден път от някоя проходима клетка в лабиринта до долния десен ъгъл в лабиринта.

## Динамично и обработка на текст

> Задача 4.

Ванката е тежък developer. И както всеки тежък developer, той трябва да измисли свой готин мотин алгоритъм. Дошла му идея да си направи алгоритъм за компресия на низове. Защо низове - защото всичко може да се прекара през хеш алгоритъм или нещо подобно и да се превърне в текст.
Идеята на Ванката била следната:

нека имаме низът "aaaabbbdZZZZZgggg".
**Важното е низът да не съдържа цифри**. Заместваме всяка непрекъсната последователност от символи X с низа XN, където N е дължината на последователността.
Единичните символи не се заменят.

Тоест примерния низ ще се трансформира до “a4b3dZ5g4”.

Реализирайте функция, която компресира низове по алгоритъма на Ванката. Функцията приема низ и връща компресирания низ (искаме копресираният низ да е **динамично** заделен с точна дължина).
