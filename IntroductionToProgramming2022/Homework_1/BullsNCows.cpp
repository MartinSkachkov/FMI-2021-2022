#include <cstdlib>
#include <iostream>
#define N 15
using namespace std;

int main() {
    cout << "Rules of the game:\nThe secret number consists of 4 different "
            "digits from 1 to 9\n"
         << "Guess it for " << N << " attempts! Good Luck\n";
    srand(time(NULL));  //да генерира всеки път случайно число
    int lowerLimit = 1111,
        upperLimit = 9999;  // за да избегнем да се генерира 0
    int secretNumberDigits[4];  // цифрите на числото на компютъра ще ги запазя
                                // в масив
    bool foundValidSecret = false;
    int secretNumber = 0;

    do {
        int digitDifferent[10] = {1};  // 1,0,0,0,0,0,0,0,0,0
        secretNumber = (rand() % (upperLimit - lowerLimit + 1)) +
                       lowerLimit;  //генерираме случайно число
        int secretNumberCopy = secretNumber;  //примерно число 7295

        //валидация всички цифри в числото да са различни помежду си и различни
        //от 0
        while (secretNumberCopy != 0) {
            int digit = secretNumberCopy % 10;  // 5,9,2,7
            if (!digitDifferent[digit]) {       // 1 - true
                digitDifferent[digit] = true;
                secretNumberCopy /= 10;  // 729,72,7,0
            } else {
                break;
            }
        }

        if (secretNumberCopy == 0) {
            foundValidSecret = true;
        }
    } while (!foundValidSecret);

    //Тук съм тествал дали се генерира валидно число:
    cout << secretNumber << endl;

    //слагам цифрите на тайното число в масив
    for (int i = 3; i >= 0; i--) {
        secretNumberDigits[i] = secretNumber % 10;
        secretNumber /= 10;
    }

    //числото на потребителя
    bool foundValidGuess = true;
    int guess, guessCopy, N_turns = 0;

    while (true) {
        do  // потребителят въвежда числото
        {
            cout << "Enter your guess: ";
            cin >> guess;  //примерно число: 1562
            if (guess < 1111 || guess > 9999) {
                cout << "Invalid input! The number should be between 1111 and "
                        "9999\n";
                foundValidGuess = false;
            } else {
                foundValidGuess = true;
            }

        } while (!foundValidGuess);

        guessCopy = guess;

        //слагам цифрите на числото на потребителя в масив
        int guessDigits[4] = {0};
        for (int i = 3; i >= 0; i--) {
            guessDigits[i] = guess % 10;
            guess /= 10;
        }

        N_turns++;  // инкрементирам броя на опитите

        //брой бикове
        bool guess_digit_used[4] = {0};
        bool secret_digit_used[4] = {0};
        int countBulls = 0;
        for (int i = 0; i <= 3; i++) {
            if (secretNumberDigits[i] == guessDigits[i]) {
                countBulls++;
                guess_digit_used[i] = true;
                secret_digit_used[i] = true;
            }
        }

        if (countBulls == 4 && N_turns <= N) {
            cout << "Congratulations you won!\n";
            cout << "It took you " << N_turns << " guess(es)" << endl;
            break;
        }
        if (countBulls != 4 && N_turns > N) {
            cout << "You lost :( Try again!\n";
            return 0;
        }
        //брой крави
        int countCows = 0;
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 3; j++) {
                if (secret_digit_used[i] || guess_digit_used[j]) {
                    continue;
                }
                if (secretNumberDigits[i] == guessDigits[j]) {
                    countCows++;
                    secret_digit_used[i] = true;
                    guess_digit_used[j] = true;
                }
            }
        }
        cout << "Turn " << N_turns << ": Your guess " << guessCopy << " has "
             << countBulls << " bulls and " << countCows << " cows." << endl;
    }

    return 0;
}