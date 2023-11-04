//
// Created by Aidan Kaneshiro and Steven Lam on 10/20/2023.
//

#include "Node.h"
#include "Card.h"

// Node constructor for creating a node that holds a card
Node::Node(const Card &value) {
    val = value;
    next = nullptr;
}