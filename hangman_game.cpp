// Chase Meyers and Mason Wilder
// CS202 Capstone Project
// May 5, 2026

#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <algorithm>
#include <cctype>
#include "hangman.h"

using namespace std;

bool areVectorsEqualIgnoreCase(const vector<char> &v1, const vector<char> &v2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (tolower(v1[i]) != tolower(v2[i]))
        {
            return false; // Mismatch found
        }
    }
    return true; // All elements match ignore case
}

bool isLetterFound(char letter, const vector<char> &v1, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (tolower(v1[i]) == tolower(letter))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    bool game_end = false;
    char letter_guess;
    string phrase_guess;
    int guess_size;
    vector<char> vphrase_guess;
    string phrase = "";
    cout << "Enter a phrase: ";
    getline(cin, phrase);

    int size = phrase.length();

    vector<char> vphrase;
    vector<char> guessing_phrase;

    Hangman hangman;

    hangman.buildMan();

    // Create vector from entered phrase
    for (int i = 0; i < size; i++)
    {
        vphrase.push_back(phrase[i]);
    }

    // Create parallel vector with unknown letters
    for (int i = 0; i < size; i++)
    {
        if (vphrase[i] != ' ')
        {
            guessing_phrase.push_back('_');
        }
        else
        {
            guessing_phrase.push_back(' ');
        }
    }

    // for testing the vectors:
    for (int i = 0; i < size; i++)
    {
        cout << vphrase[i];
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << guessing_phrase[i];
    }
    cout << endl;

    while (!game_end)
    {
        cout << "Guess a letter (type 0 - guess the phrase): ";
        // implement a throw exception if user doesn't enter a char (letter_guess data type) or 0
        cin >> letter_guess;

        if (letter_guess == 48)
        {
            cout << "Guess the phrase: ";
            cin >> phrase_guess;
            guess_size = phrase_guess.length();

            for (int i = 0; i < guess_size; i++)
            {
                guessing_phrase.push_back(tolower(phrase_guess[i]));
            }

            if (areVectorsEqualIgnoreCase(vphrase, guessing_phrase, size))
            {
                cout << "Guessing Player won! The Phrase was correctly guessed." << endl;
                return 0;
            }
            else
            {
                cout << "Guessing Player lost. The phrase was incorrectly guessed." << endl;
                return 0;
            }
        }

        if (isLetterFound(letter_guess, vphrase, size)) // if guess letter is found
        {
            cout << "The guessed letter was found! :)" << endl;
            for (int i = 0; i < size; i++)
            {
                if (tolower(vphrase[i]) == tolower(letter_guess))
                {
                    guessing_phrase[i] = vphrase[i];
                }
            }
        }
        else
        {
            cout << "The guessed letter was NOT found. :(" << endl;
        }

        if (areVectorsEqualIgnoreCase(vphrase, guessing_phrase, size))
        {
            cout << "Guessing Player has Won!" << endl;
            return 0;
        }
        for (int i = 0; i < size; i++)
        {
            cout << guessing_phrase[i];
        }
        cout << endl;
    }

    return 0;
}