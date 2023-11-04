#include "Deck.h"
#include <string>
#include "Node.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Deck constructor that initializes a linked list of 52 card nodes
Deck::Deck() : head(nullptr) {
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    // Nested loops to create a node for each card in the deck
    for (const string& suit : suits) {
        for (const string& value : values) {
            Node* newCardNode = new Node(Card(suit, value));

            // If the deck is empty.
            if (!head) {
                head = newCardNode;
            } else {
                // Adding to the end of the deck.
                Node* current = head;
                while (current->next) {
                    current = current->next;
                }
                current->next = newCardNode;
            }
        }
    }
}

// Deck destructor to free all the nodes in the list
Deck::~Deck() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Overloaded output operator to print the whole deck
ostream & operator<<(ostream &out, const Deck &d){
    Node *curr = d.head;

    while(curr != nullptr){
        out << curr->val;
        curr = curr->next;
    }
    return out;
}

// Method to shuffle the deck of cards
void Deck::shuffle() {
    Node *curr = head;
    vector<Node*> nodes = {};

    // Collect all node pointers into a vector
    while (curr != nullptr){
        nodes.push_back(curr);
        curr = curr->next;
    }
    ::random_shuffle(nodes.begin(), nodes.end()); // Use random_shuffle to randomly rearrange the nodes in the vector

    // Re-link the nodes in the order given by the shuffled vector
    for (int i =0; i < nodes.size(); i++) {
        if (i == 0) {
            head = nodes[i];
        }
        if (i != nodes.size()-1) {
            nodes[i]->next = nodes[i+1];
        }
        else {
            nodes[i]->next = nullptr;
        }
    };
    return;
}