#pragma once

#include <iostream>
#include "Card.h"
#include "Node.h"

class Deck {

private:
    Node *head;

public:
    Deck();
    ~Deck();

    friend ostream & operator<<(ostream &out, const Deck &d);
    void shuffle();
};


