# Задачи

## Задача 1

> Да се създаде структура Jedi със следните полета

- име
- възраст
- сила
- LightSaber
- живот (в началото всеки започва с 100)

> Да се създаде структура LightSaber със следните полета

- цвят
- тип

Типовете lightsaber-и са ограничени до:

- SINGLEBLADED
- DOUBLE_BLADED
- CROSSGUARD

Да се реализират следните методи:

1. void initializeSaber(Jedi& jedi) - инициализира light saber-a на подадения като параметър jedi
2. void initializeJedi(Jedi& jedi) - инициализира полетата на подадения jedi
3. void printSaber(LightSaber& lightSaber) - принтира на конзолата информация за light saber
4. void printJedi(Jedi& jedi) - принтира на конзолата информация за jedi
5. void killJedi(Jedi& jedi) - освобождава заетата динамична памет от jedi (_lightsaber-a също може да има динамична памет_)
6. void battle(Jedi& jedi1, Jedi& jedi2) - извършва се епична битка между 2 jedis като идеята е всеки загубва точки живот по следната формула:

```
(сила * тип на lightsaber * брой букви от цвета на lightsaber) / възраст
```

Битката се извършва, докато един от двамата не остане с 0 точки живот. Ако и двама останат с 0 точки живот, няма победител. В противен случай, да се изведе съобщение кой е победителят!
Да се изпробват всички методи с подходящи примери!

## :cucumber: :onion: Задача 2.

### Вие сте домакини в "Черешката на тортата". Имате за задача да приготвите салата за своите гости. За целта трябва да създадете:

> структура Vegetable, която съдържа:

- име на зеленчука name;
- вкус на зеленчука taste - една от константите SOUR, SWEET, BITTER, SPICY;
- нецелочислен грамаж на зеленчука weight в грамове.

> структура Dressing, която съдържа:

- име на дресинга name;
- вкус на дресинга taste - една от константите SOUR, SWEET, BITTER, SPICY;
- нецелочислен грамаж quantity в милилитри;
- алергени alergens като масив от низове.

> структура Salad със следните полета:

- брой на зеленчуците в салатата;
- масив от зеленчуци;
- брой на дресингите в салатата;
- масив от дресинги.

Създайте член-фунцкия (в подходящата структура), която:

- прочита от стандартния вход и въвежда информация за салата;
- определя колко грама тежи дадена салата, ако приемете, че 1мл тежи, колкото 1 гр: double getWeight();
- определя вкус на салатата спрямо това кой вкус се повтаря най-много пъти в съставките: Taste getTaste();
- извежда алергените в дадена салата: void printAlergens();
- отпечатва информация за салата в следния формат:

------------------- <ИМЕ*НА*САЛАТАТА> -------------------

Contents: <зеленчук_1>, ..., <зеленчук_n>,
<дресинг_1>, ..., <дресинг_m>

Quantity: <грамаж>

Description: <вкус>

Alergens: <алергени>

------------------------- Bon appetit! -------------------------
