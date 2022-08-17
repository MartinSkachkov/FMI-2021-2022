#include <iostream>
#define GRID_SIZE 3
#define WORD_SIZE 10
using namespace std;

int strlen(char* str) {
	int len = 0;
	while (*str != 0) {
		str++;
		len++;
	}
	return len;
}

void resetVisitedMatrix(bool visited[][GRID_SIZE]) {
	for (size_t i = 0; i < GRID_SIZE; i++) {
		for (size_t j = 0; j < GRID_SIZE; j++) {
			visited[i][j] = 0;
		}
	}
}

bool isSafe(char grid[][GRID_SIZE], char* word, size_t letter, size_t currX, size_t currY) {
	if ((currX >= 0 && currX < GRID_SIZE) && (currY >= 0 && currY < GRID_SIZE) && grid[currX][currY] == word[letter]) {
		return true;
	}
	return false;
}


bool foundWord(char grid[][GRID_SIZE], char* word, bool visited [][GRID_SIZE], size_t currX, size_t currY, int wordLen,int currWordLen, size_t letter) {
	//base case
	if (wordLen == currWordLen - 1 && grid[currX][currY] == word[letter]) {
		wordLen++;
		letter++;
		visited[currX][currY] = 1;
		return true;
	}

	if (isSafe(grid, word, letter, currX, currY)) {
		if (visited[currX][currY]) {
			return false;
		}

		visited[currX][currY] = 1;
		letter++;
		wordLen++;

		if (foundWord(grid, word, visited, currX + 1, currY, wordLen, currWordLen, letter) == true) {
			return true;
		}

		if (foundWord(grid, word, visited, currX , currY+1, wordLen, currWordLen, letter) == true) {
			return true;
		}

		if (foundWord(grid, word, visited, currX -1, currY, wordLen, currWordLen, letter) == true) {
			return true;
		}

		if (foundWord(grid, word, visited, currX , currY-1, wordLen, currWordLen, letter) == true) {
			return true;
		}

		//backtrack
		visited[currX][currY] = 0;
		wordLen--;
		letter--;
		return false;
	}
	return false;
}

int crossword(char grid[][GRID_SIZE], char** words, size_t n) {
	bool visited[GRID_SIZE][GRID_SIZE];
	resetVisitedMatrix(visited);
	int maxLen = INT_MIN;
	bool foundAWord = false;

	//iterate through each word
	for (size_t word = 0; word < n; word++) {
		foundAWord = false;
		int currWordLen = strlen(words[word]);

		//check the whole crossword if this word is in it
		for (size_t gridX = 0; gridX < GRID_SIZE; gridX++) {
			for (size_t gridY = 0; gridY < GRID_SIZE; gridY++) {
				foundAWord = foundWord(grid,words[word],visited,gridX,gridY,0,currWordLen,0);
				resetVisitedMatrix(visited);
				//case we found a valid word in the crossword
				if (!foundAWord) {
					continue;
				}
				else {
					if (maxLen < currWordLen) {
						maxLen = currWordLen;
					}
					break;
				}
			}
			if (!foundAWord) {
				continue;
			}
		}
		if (!foundAWord) {
			continue;
		}
	}
	return maxLen;
}

int main() {
	cout << "grid:\n";
	//this is the puzzle
	char grid[GRID_SIZE][GRID_SIZE];
	for (size_t i = 0; i < GRID_SIZE; i++){
		for (size_t j = 0; j < GRID_SIZE; j++){
			cin >> grid[i][j];
		}
	}

	size_t n;
	cout << "number of words: ";
	cin >> n;

	char** words = new (nothrow) char*[n];
	if (!words) {
		cout << "couldn't allocate memory!";
		return -1;
	}
	cin.ignore();
	for (size_t i = 0; i < n; i++) {
		words[i] = new (nothrow) char[WORD_SIZE];
		if (!words[i]) {
			cout << "couldn't allocate memory!";
			return -1;
		}
		cout << "str: ";
		cin.getline(words[i], WORD_SIZE);
	}

	cout << "max len: " << crossword(grid,words,n);

	for (size_t i = 0; i < n; i++) {
		delete[] words[i];
	}
	delete[] words;
	return 0;
}
