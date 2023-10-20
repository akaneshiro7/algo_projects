//
// Created by Aidan Kaneshiro on 10/20/2023.
//

#include "Node.h"
#include "Card.h"

//Node::Node(){
//    val = Card();
//    next = nullptr;
//}

Node::Node(const Card &value) {
    val = value;
    next = nullptr;
}

//Node::Node(const Card &value, Node *n) {
//    val = value;
//    next = n;
//}