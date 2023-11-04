#pragma once

#include "Card.h"

// Class Node represents a node in a linked list of cards
class Node {
public:
    Card val; // The card value stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor declaration
    Node(const Card& value);
};

