#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int isAlreadyGuessed(char guessedLetters[], char letter) {
    for (int i = 0; guessedLetters[i] != '\0'; i++) {
        if (guessedLetters[i] == letter)
            return 1;
    }
    return 0;
}

int checkLetter(char *word, char guess, char guessedLetters[]) {
    int found = 0;
    int len = strlen(guessedLetters);

    guessedLetters[len] = guess;
    guessedLetters[len + 1] = '\0';

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == guess)
            found = 1;
    }
    return found;
}

int main() {
    char words[5][10] = {"apple", "banana", "tree", "book", "water"};
    srand(time(NULL));

    int index = rand() % 5;
    char *word = words[index];

    int length = strlen(word);
    char display[20];
    char guessedLetters[26] = "";
    int attempts = 6;
    char guess;

    for (int i = 0; i < length; i++)
        display[i] = '_';
    display[length] = '\0';

    printf("Welcome to Word Guessing Game!\n");

    while (attempts > 0) {
        printf("\nWord: ");
        for (int i = 0; i < length; i++)
            printf("%c ", display[i]);

        printf("\nAttempts left: %d", attempts);
        printf("\nEnter a letter: ");
        scanf(" %c", &guess);

        if (isAlreadyGuessed(guessedLetters, guess)) {
            printf("Already guessed!\n");
            continue;
        }

        if (checkLetter(word, guess, guessedLetters)) {
            for (int i = 0; i < length; i++) {
                if (word[i] == guess)
                    display[i] = guess;
            }
        } else {
            attempts--;
        }

        if (strcmp(display, word) == 0) {
            printf("\nCongratulations! You guessed the word: %s\n", word);
            return 0;
        }
    }

    printf("\nGame Over! Word was: %s\n", word);
    return 0;
}

