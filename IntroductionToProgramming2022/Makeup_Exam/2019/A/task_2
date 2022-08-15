#include <iostream>
#define GRID_SIZE 3
#define WORD_LEN 10
using namespace std;

bool validateGrid(char letter) {
	if (letter < 'a' || letter >'z') {
		return false;
	}
	return true;
}

bool validateWord(char* word) {
	size_t len = strlen(word);
	for (size_t i = 0; i < len; i++) {
		if (word[i] < 'a' || word[i] > 'z') {
			return false;
		}
	}
	return true;
}

bool isSafe(char grid[][GRID_SIZE], char* word, size_t letter, size_t currX, size_t currY) {
	if ((currX >= 0 && currX <= GRID_SIZE - 1) && (currY >= 0 && currY <= GRID_SIZE - 1) && grid[currX][currY] == word[letter]) {
		return true;
	}
	return false;
}

bool findWord(char grid[][GRID_SIZE], bool visited[][GRID_SIZE], char* word, size_t currX, size_t currY, size_t currWordLen, size_t countLen, size_t letter) {
	//base case
	if (countLen == currWordLen - 1 && grid[currX][currY] == word[letter]) {
		letter++;
		countLen++;
		visited[currX][currY] = 1;
		return true;
	}

	if (isSafe(grid, word, letter,currX,currY)) {
		if (visited[currX][currY]) {
			return false;
		}

		visited[currX][currY] = 1;
		letter++;
		countLen++;

		if (findWord(grid, visited, word, currX + 1, currY, currWordLen, countLen, letter) == true) {
			return true;
		}
		if (findWord(grid, visited, word, currX , currY + 1, currWordLen, countLen, letter) == true) {
			return true;
		}
		if (findWord(grid, visited, word, currX - 1, currY, currWordLen, countLen, letter) == true) {
			return true;
		}
		if (findWord(grid, visited, word, currX , currY - 1, currWordLen, countLen, letter) == true) {
			return true;
		}

		visited[currX][currY] = 0;
		letter--;
		countLen--;
		return false;
	}
	return false;
}

void resetVisited(bool visited[][GRID_SIZE]) {
	for (size_t i = 0; i < GRID_SIZE; i++) {
		for (size_t j = 0; j < GRID_SIZE; j++) {
			visited[i][j] = 0;
		}
	}
}

bool crossword(char grid[][GRID_SIZE], char** words, bool visited[][GRID_SIZE], size_t n) {
	bool foundWord = false;

	for (size_t word = 0; word < n; word++) {
		foundWord = false;
		//char firstLetter = words[word][0];
		//char endIndex = strlen(words[word]) - 1;
		size_t currWordLen = strlen(words[word]);
		for (size_t gridX = 0; gridX < GRID_SIZE; gridX++)
		{
			for (size_t gridY = 0; gridY < GRID_SIZE; gridY++)
			{
				foundWord = findWord(grid, visited, words[word], gridX, gridY, currWordLen, 0, 0);
				if (!foundWord) {
					continue;
				}
				else {
					resetVisited(visited);
					break;
				}
			}
			if (!foundWord) {
				continue;
			}
			else {
				break;
			}
		}
		if (!foundWord) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << "grid:\n";
	char grid[GRID_SIZE][GRID_SIZE];
	for (size_t i = 0; i < GRID_SIZE; i++) {
		for (size_t j = 0; j < GRID_SIZE; j++) {
			cin >> grid[i][j];
			if (!validateGrid(grid[i][j])) {
				cout << "shold be a letter! enter again\n";
				cin >> grid[i][j];
			}
		}
	}

	size_t n;
	cout << "number of words: ";
	cin >> n;

	char** words = new (nothrow) char* [n];
	if (!words) {
		cout << "could'n allocate memory!";
		return -1;
	}

	cin.ignore();
	for (size_t i = 0; i < n; i++) {
		words[i] = new (nothrow) char[WORD_LEN];
		if (!words[i]) {
			cout << "could'n allocate memory!";
			return -1;
		}

		do {
			cout << "word: ";
			cin.getline(words[i], WORD_LEN);
		} while (!validateWord(words[i]));
	}

	bool visited[GRID_SIZE][GRID_SIZE] = { false };

	cout << "crossword can be solved? " << boolalpha << crossword(grid, words,visited,n);

	for (size_t i = 0; i < n; i++) {
		delete[] words[i];
	}
	delete[] words;
	return 0;
}
