# Задачи

> Бройни системи
- превърни от двоично в десетично число:
    - 1010 0010(2) - ???(10) <details><summary>Отговор</summary>162</details>
    - 1001 1010(2) - ???(10) <details><summary>Отговор</summary>154</details>
    - 0010 1001 1010 - ???(10) <details><summary>Отговор</summary>666</details>

- превърни от десетично в двоично число:
    - 42(10) - ???(2) <details><summary>Отговор</summary>0010 1010</details>
    - 404(10) - ???(2) <details><summary>Отговор</summary>0001 1001 0100</details>
    - 500(10) - ???(2) <details><summary>Отговор</summary>0001 1111 0100</details>

- превърни от осмично в десетично число:
    - 420(8) - ???(10) <details><summary>Отговор</summary>272</details>
    - 1024(8) - ???(10) <details><summary>Отговор</summary>532</details>
    - 377(8) - ???(10) <details><summary>Отговор</summary>255</details>

- превърни от десетично в осмично число:
    - 91(10) - ???(8) <details><summary>Отговор</summary>133</details>
    - 455(10) - ???(8) <details><summary>Отговор</summary>707</details>
    - 137 (10) - ???(8) <details><summary>Отговор</summary>211</details>

- превърни от шестнадесетично в десетично число:
    - 11a(16) - ???(10) <details><summary>Отговор</summary>282</details>
    - c4(16) - ???(10) <details><summary>Отговор</summary>196</details>
    - 5e(16) - ???(10) <details><summary>Отговор</summary>94</details>

- превърни от осмично в шестнадесетично, **без да преминаваш през десетично**:
    - 77(8) - ???(16) <details><summary>Отговор</summary>3f</details>
    - 56(8) - ???(16) <details><summary>Отговор</summary>2e</details>
    - 256(8) - ???(16) <details><summary>Отговор</summary>ae</details>

<details>
    <summary>
    <b>Подсказка</b>
    </summary>
    осмично -> двоично -> шестнадесетично

    - За да преминеш от осмично в двоично, трябва да представиш всяка цифра на осмичното число с 3 бита.

    - За да преминеш от двоично в шестнадесетично, трябва да групираш битовете в група по 4 и да изчислиш за всяка група съответната шестнадесетично цифра на числото (резултата).

    Пример:
    = 56(8)

    = (101)(110) // просто визуално разделяне, не е умножение

    = (101110)2

    = (10)(1110)

    = (2)(14)

    = 2e(16)
 
</details>


- сума на двоични числа:
    - 1110 + 0111 = ?? <details><summary>Отговор</summary>0001 0101</details>
    - 1101 1001 + 0001 1010 = ?? <details><summary>Отговор</summary>1111 0011</details>

- изваждане на двоични числа:
    - 1110 - 0111 = ?? <details><summary>Отговор</summary>0111</details>
    - 1101 1001 - 0001 1010 = ?? <details><summary>Отговор</summary>1011 1111</details>

- умножение на двоични числа:
    - 1110 * 0111 = ?? <details><summary>Отговор</summary>0110 0010</details>
    - 1101 1001 * 0001 1010 = ?? <details><summary>Отговор</summary>0001 0110 0000 1010</details>

- деление на двоични числа:
    - 0100 0110 / 111 = ?? <details><summary>Отговор</summary>1010</details>
    - 0001 1110 / 110 = ?? <details><summary>Отговор</summary>101</details>

## Tипове в C++ 
> 1. Кой тип най-вероятно бихме използвали, ако искаме да създадем променлива, която съдържа:
- първата буква от името ни;
- числото пи;
- решението на уравнението |x| <= 7;
- корен квадратен от някакво число;
- числото 2^32;
- само 0 или 1, без да е позволена друга стойност;
- знака '+';
- някоя година в историята на човечеството.
## По-сложни задачки

1) [Яки числа](http://www.math.bas.bg/infos/files/2014-01-07-C3.pdf)

2) [Боядисване на отсечки](http://www.math.bas.bg/infos/files/2015-01-04-B2.pdf)

3) ASCII-Art

Дадени са ви три символа измежду следните: ‘f’, ‘m’, ‘i’. 

В зависимост от това, какви са въведените символи, изведете на екрана техните ASCII Art representations (т.е. ако сте въвели ‘f’, изведете F изписано само с буквата ‘f’ и т. нат.). 

Целта е това извеждане да стане с възможно най-малко на брой cout-ове, като нямате право да използвате функции и масиви.