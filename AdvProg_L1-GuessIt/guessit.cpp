#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


/***
    Args:

    Returns:
        number (int) : random number in range 1-100
***/



int generateRandomNumber() {
    srand(time(0));
    return rand() % 100 + 1;
}



/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {

    int guess;
    cout << "Enter your guess (1 - 100): ";
    cin >> guess;


    while (cin.fail() || guess < 1 || guess > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Please enter a number between 1 and 100: ";
        cin >> guess;
    }


    return guess;
}


/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    if (number > randomNumber) {
        return "Your number is higher.";
    } else if (number < randomNumber) {
        return "Your number is lower.";
    } else {
        return "Congratulation! You win.";
    }
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    return (answer == "Correct! You guessed the right number.");
}



/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    return (isContinued == 'y' || isContinued == 'Y');
}


/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    char isContinued;
    cout << "Do you want to continue playing? (y/n): ";
    cin >> isContinued;


    while (isContinued != 'y' && isContinued != 'n' && isContinued != 'Y' && isContinued != 'N') {
        cout << "Invalid input! Please enter 'y' (yes) or 'n' (no): ";
        cin >> isContinued;
    }

    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
