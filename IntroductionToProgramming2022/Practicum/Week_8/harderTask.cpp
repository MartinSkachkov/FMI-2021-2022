#include <iostream>
#include <cstring>
#define MAX_LEN 1025
using namespace std;

size_t strlen(char* str) {
	size_t len = 0;
	while (*str != 0) {
		len++;
		str++;
	}
	return len;
}

// copy data from source to destination
/*void strcpy(char* destination, const char* source) {
	size_t length = strlen(source);
	for (size_t i = 0; i <= length; i++) {
		destination[i] = source[i];
	}
}*/

int strcmpRec(const char* str1, const char* str2) {
	if (*str1 > *str2) {
		return 1;
	}
	if (*str1 < *str2) {
		return -1;
	}
	if (*str1 == 0) {
		return 0;
	}
	return strcmpRec(str1 + 1, str2 + 1);
}


void addWord(char**& result, char* sentence, size_t startIndex, size_t endIndex, size_t& size) {
	char** newResult = new char* [size + 1]; //plus one because we add a new word

	//copy the old words to the new result arr
	for (size_t i = 0; i < size; i++) {
		newResult[i] = new char[strlen(result[i]) + 1]; //allocate memory for each old word
		strcpy_s(newResult[i], strlen(result[i]) + 1, result[i]);
		delete[] result[i];
	}
	delete[] result;

	//adding the last word
	newResult[size] = new char[endIndex - startIndex + 1];
	size_t iterator = 0;
	for (size_t i = startIndex; i < endIndex; i++) {
		newResult[size][iterator++] = sentence[i];
	}

	newResult[size][iterator] = 0;
	size++;
	result = newResult;
}

char** extractWords(char* sentence, size_t& size) {
	size_t start = 0;
	size_t end = strlen(sentence) - 1;

	//trim from the beginning
	while (sentence[start] == ' ') {
		start++;
	}

	//trim from the end
	while (sentence[end] == ' ') {
		end--;
	}

	char** result = nullptr;
	size_t startIndex = start;

	for (size_t i = start; i < end; i++)
	{
		if (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '!') {
			addWord(result, sentence, startIndex, i, size);
			startIndex = i + 1;
		}
	}

	if (size != 0 || (start == 0 && end == strlen(sentence) - 1)) {
		addWord(result, sentence, startIndex, end + 1, size);
	}
	return result;
}

void lexicographySort(char** wordCollection, size_t size) {
	char* temp = nullptr;
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (strcmpRec(wordCollection[i], wordCollection[j]) > 0) {

				temp = new char[strlen(wordCollection[i]) + 1];
				strcpy_s(temp, strlen(wordCollection[i]) + 1, wordCollection[i]);
				delete[] wordCollection[i];

				wordCollection[i] = new char[strlen(wordCollection[j]) + 1];
				strcpy_s(wordCollection[i], strlen(wordCollection[j]) + 1, wordCollection[j]);
				delete[] wordCollection[j];

				wordCollection[j] = new char[strlen(temp) + 1];
				strcpy_s(wordCollection[j], strlen(temp) + 1, temp);
				delete[] temp;
			}
		}
	}
}

void print(char** wordCollection, size_t size) {
	for (size_t i = 0; i < size; i++) {
		cout << wordCollection[i] << '\n';
	}
}

int main() {
	size_t sentenceLen;
	do {
		cout << "sentence len: ";
		cin >> sentenceLen;
	} while (sentenceLen > 1024);

	cout << "sentence: ";
	char* sentence = new char[sentenceLen + 1]; //for null-terminator
	cin.ignore();
	cin.getline(sentence, sentenceLen + 1);

	size_t size = 0;
	char** wordCollection = extractWords(sentence, size);
	lexicographySort(wordCollection, size);
	print(wordCollection, size);

	for (size_t i = 0; i < size; i++) {
		delete[] wordCollection[i];
	}
	delete[] sentence;
	return 0;
}