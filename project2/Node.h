#pragma once

#include "Card.h"

class Node {
public:
    Card val;
    Node *next;

//    Node();
    Node(const Card& value);
//    Node(const Card& value, Node *n);
};

