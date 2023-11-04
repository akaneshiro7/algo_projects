#pragma once

#include <iostream>
#include "Card.h"
#include "Node.h"

// Class Deck represents a deck of playing cards
class Deck {

private:
    Node *head; // Pointer to the first node in the linked list of cards

public:
    Deck(); // Constructor to create and initialize a full deck of cards
    ~Deck(); // Destructor to clean up the linked list

    // Friend function to enable direct streaming of the Deck object
    friend ostream & operator<<(ostream &out, const Deck &d);
    void shuffle(); // Method to shuffle the cards in the deck
};


