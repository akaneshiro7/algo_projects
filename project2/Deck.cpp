#include "Deck.h"
#include <string>
#include "Node.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

Deck::Deck() : head(nullptr) {
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

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

Deck::~Deck() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

ostream & operator<<(ostream &out, const Deck &d){
    Node *curr = d.head;

    while(curr != nullptr){
        out << curr->val;
        curr = curr->next;
    }
    return out;
}

void Deck::shuffle() {
    Node *curr = head;
    vector<Node*> nodes = {};
    while (curr != nullptr){
        nodes.push_back(curr);
        curr = curr->next;
    }
    ::random_shuffle(nodes.begin(), nodes.end());

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