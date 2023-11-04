#pragma once
#include "Card.h"
#include "Node.h"

// Declaration of the Deck class.
class Deck {
private:
    Node *head; // Pointer to the top card of the deck.

public:
    // Constructors and destructor
    Deck();
    ~Deck();

    // Function to deal and replace cards
    Card deal();
    void replace(const Card& card);

    // Friend function to overload << for printing Decks.
    friend ostream & operator<<(ostream &out, const Deck &d);

    // Function to shuffle the deck.
    void shuffle();
};

// Declaration of the game function.
void playFlip(Deck& deck);
