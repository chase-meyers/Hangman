//Chase Meyers and Mason Wilder
//CS202 Capstone Project
//May 5, 2026

#ifndef HANGMAN_H
#define HANGMAN_H

using namespace std;

class Node
{
    public:
        Node(char);
        Node& operator=(const Node&n);

        char part;
        Node* next;
};

class Hangman
{
    public:
        Hangman();
        Hangman(const Hangman&h);
        Hangman& operator=(const Hangman&h);
        ~Hangman();

        void buildMan();
        void printHangman(int wrong_guess);

    private:
        Node *head;
        
};

#endif