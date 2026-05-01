// Chase Meyers and Mason Wilder
// CS202 Capstone Project
// May 5, 2026

#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include "hangman.h"

using namespace std;

int main()
{
    string phrase = "";
    cout << "Enter a phrase: ";
    getline(cin, phrase);

    int size = phrase.length();

    vector<char> vphrase;
    vector<char> guessing_phrase;

    Hangman hangman;

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

    /*Testing Hangman class*/
    hangman.addPart('O');
    cout << endl;
    hangman.addPart('|');
    cout << endl;
    hangman.printHangman();
    cout << endl;

    return 0;
}