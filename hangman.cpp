//Chase Meyers and Mason Wilder
//CS202 Capstone Project
//May 5, 2026

#include <iostream>
#include "hangman.h"

using namespace std;

/*Node Constructor and Assignment Operator*/
Node::Node(char p)
{
    part = p;
    next = nullptr;
}

Node& Node::operator=(const Node& n)
{
    if (this != &n)
    {
        part = n.part;
        next = n.next;
    }

    return *this;
}

/*Hangman Constructor, Copy Constructor, Deconstructor, Assignment Operator*/
Hangman::Hangman()
{
    num_parts = 0;
    guesses = 0;
    buildMan();
}

Hangman::Hangman(const Hangman& h)
{
    head = nullptr;
    buildMan();
}

Hangman::~Hangman()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

Hangman& Hangman::operator=(const Hangman& h)
{
    /*Deletes the current hangman*/
    Node* current = head;
    if (this != &h)
    {
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    /*Duplicates the passed hangman*/
    Node* h_current = h.head;
    current = nullptr;
    while (h_current != nullptr)
    {
        current = new Node(h_current->part);
        h_current = h_current->next;

        Node* temp = current;
        current = current->next;
        temp->next = current;
        delete temp;
    }

    return *this;
}

/////////////
/*Functions*/
/////////////

/*Adds the hangman's parts to the list, formatted in a manner that is easily printable*/
void Hangman::buildMan()
{
    head = new Node('O');
    head->next = new Node('/');
    head->next->next = new Node('|');
    head->next->next->next = new Node('\\');
    head->next->next->next->next = new Node('/');
    head->next->next->next->next->next = new Node('\\');
    num_parts = 6;
}

/*Prints the hangman*/
void Hangman::printHangman()
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->part << endl;
        current = current->next;
    }
}
