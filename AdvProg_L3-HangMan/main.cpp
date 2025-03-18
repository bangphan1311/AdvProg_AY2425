#include "hangman.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

int generateRandomNumber(const int min, const int max) {
    return min + rand() % (max - min + 1);
}

bool isCharInWord(const char ch, const std::string& word) {
    return word.find(ch) != std::string::npos;
}

std::string generateHiddenCharacters(std::string secretWord) {
    return std::string(secretWord.length(), '-');
}

std::string chooseWordFromList(const std::vector<std::string>& wordList, int index) {
    if (index >= 0 && index < wordList.size()) {
        return wordList[index];
    }
    return "";
}

void updateSecretWord(std::string& secretWord, const char ch, const std::string& word) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == ch) {
            secretWord[i] = ch;
        }
    }
}

void updateEnteredChars(const char ch, std::string& chars) {
    if (chars.find(ch) == std::string::npos) {
        chars += ch;
    }
}

void updateIncorrectGuess(int& incorrectGuess) {
    ++incorrectGuess;
}

void processData(const char ch, const std::string& word, std::string& secretWord,
                 std::string& correctChars, int& incorrectGuess, std::string& incorrectChars) {
    if (isCharInWord(ch, word)) {
        updateSecretWord(secretWord, ch, word);
        updateEnteredChars(ch, correctChars);
    } else {
        updateIncorrectGuess(incorrectGuess);
        updateEnteredChars(ch, incorrectChars);
    }
}
