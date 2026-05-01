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
    head = nullptr;
    tail = nullptr;
}

Hangman::Hangman(const Hangman& h)
{
    head = nullptr;
    
    if (h.head != nullptr)
    {
        Node* current = h.head;
        while (current != nullptr)
        {
            addPart(current->part);
            current = current->next;
        }
    }
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

    /*Finish this, not working*/
    current = new Node(h.head->part);
    Node* h_current = h.head;
    while (h_current != nullptr)
    {
        current->part = h_current->part;
        current->next = new Node(h_current->part);
        current = current->next;
        h_current = h_current->next;
    }
}

void Hangman::addPart(char part)
{
    Node* newNode = new Node(part);
    num_parts++;

    switch (part)
    {
        case 'O':
            head = newNode;
            break;
        case '|':
            head->next = newNode;
            break;
        case '/':
            head->next = newNode;
            break;
        case '\\':
            Node* current = head;
            while (current->part != '|')
            {
                current = current->next;
            }
            current->next = newNode;
            break;
    }
}

void Hangman::printHangman()
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->part << endl;
        current = current->next;
    }
}
