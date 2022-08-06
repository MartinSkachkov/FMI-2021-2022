bool labyrint[8][8] = {
    {1, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1},
    ... {1, 0, 0, 0, 1, 1, 1, 1},
};
// …
bool way(bool labyrinth[][8], int size, int x, int y) {
    // напуснали сме границите на лабиринта
    if (x < 0 || y < 0 || x > size - 1 || y > size - 1) {
        return false;
    }
    // целта е достигната
    if (x == size - 1 && y == size - 1) {
        return true;
    }
    // клетката е непроходима
    if (!labyrint[x][y]) {
        return false;
    }
    // обявяваме клетката за обходена, за да се предотврати зацикляне
    // Ще го разгледаме на следващата лекция
    labyrint[x][y] = 0;
    //търсене на път от някой от четирите съседа
    return way(labyrinth, size, x + 1, y) || way(labyrinth, size, x, y + 1) ||
           way(labyrinth, size, x - 1, y) || way(labyrinth, size, x, y - 1);
}