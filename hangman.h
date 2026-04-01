//Chase Meyers and Mason Wilder
//CS202 Capstone Project
//May 5, 2026

using namespace std;

#ifndef HANGMAN_H
#define HANGMAN_H

class Node
{
    public:
        Node();
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

        void addPart();
        void printHangman();
        
        int numParts;
        Node *head;
};

#endif