#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver = false; // global variable
bool restart = false;
// map grid
const int width = 20;
const int height = 20;
int headX, headY, fruitX, fruitY, score;
int tailX[100], tailY[100];//array declared inside the main function contain garbage values by default, 
//but the array declared globally are initialized to 0 value by default
int nTail = 0;

//https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-enum
enum eDirection {
	STOP = 0,
	UP, DOWN,
	LEFT, RIGHT
};
eDirection dir; // declare enum variable

void Setup() {
	//starting point
	gameOver = false;
	dir = STOP;
	headX = width / 2;
	headY = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

//clears flickering
void ClearScreen()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Draw() {

	ClearScreen();//system("cls"); //system("clear");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == headY && j == headX)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool printedTail = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k]==j && tailY[k]==i)
					{
						cout << 'o';
						printedTail = true;
						break;
					}
				}
				if (!printedTail)
				{
					cout << " ";
				}	
			}


			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}

void Input() {
	if (_kbhit()) // if a key is pressed == 1 else == 0
	{
		switch (_getch()) // gets the ascii of the character pressed from the keyboard so it cant be false
		{
		case 'a':dir = LEFT; break;
		case 'd':dir = RIGHT; break;
		case 'w':dir = UP; break;
		case 's':dir = DOWN; break;
		case 27:gameOver = true; break; // 27 is the ascii for esc button
		case '\n':restart = true; break;
		}
	}
}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = headX;
	tailY[0] = headY;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case UP: headY--;
		break;
	case DOWN:headY++;
		break;
	case LEFT:headX--;
		break;
	case RIGHT:headX++;
		break;
	}
	//border
	if (headX < 0 || headX>width || headY > height || headY < 0)
	{
		gameOver = true;
	}

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == headX && tailY[i] == headY )
		{
			gameOver = true;
		}
	}

	if (headX == fruitX && headY == fruitY)
	{
		nTail++;
		score += 10;
		fruitX = rand() % height;
		fruitY = rand() % width;
	}
}

int main() {
	Setup();
	while (!gameOver && !restart)
	{
		Draw();
		Input();
		Logic();
		if (score < 50)
		{
			Sleep(190);
		}
		else if (score >= 50 && score<100) {
			Sleep(150);
		}
		else if (score >= 100 && score<150) {
			Sleep(110);
		}
		else if (score >= 150 && score<200) {
			Sleep(80);
		}
		else if (score >= 200 && score < 250) {
			Sleep(40);
		}
		else
		{
		Sleep(230);
		}
	}

	return 0;
}
