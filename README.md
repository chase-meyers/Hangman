# Hangman

This is the final lab for CS202: Hangman CLI - A 2-player game

# How to run and play

To compile, run this command: g++ hangman.cpp hangman_game.cpp -o hangman
To run the game, run this command: ./hangman

When prompted for a phrase, type out a phrase and press enter

Then (a different player) types a letter to guess that might be in that phrase.
Then you can keep guessing that same way.

Once you 'know' the phrase, you enter '0' and type in that EXACT phrase.

# How to win (or lose)

Guessing player gets 6 total incorrect letter guesses until lost
Guessing player gets 1 incorrect phrase guess until lost
Guessing player wins if they guess all of the letters correct or correct exact phrase.
