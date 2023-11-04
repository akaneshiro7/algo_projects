#include "Deck.h"
#include <string>
#include "Node.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Function to simulate playing a card-flipping game.
void playFlip(Deck& deck) {
    // Initialized variables like score, hand, and input
    int score = 0;
    vector<Card> hand;
    string input;

    // Deals 24 cards and stores in vector
    for(int o = 0; o < 24; o++) {
        hand.push_back(deck.deal());
    }

    // Prints the hand
    cout << "The top 24 cards are: " << endl;
    for (int j = 0; j < 24; j++) {
        cout << hand[j];
    }

    // Prints the remaining cards in the deck
    cout << endl;
    cout << "The remaining deck is: " << endl << deck;

    // while loop to continue playing as long as hand is not empty and user wants to play
    while(!hand.empty()) {
        cout << "Current score: " << score << endl;
        cout << "Flip a card? (y/n): ";
        cin >> input;

        // User flips a card
        if (input == "y" || input == "Y") {
            Card flippedCard = hand.back(); // sets flippedCard to back element of vector
            hand.pop_back(); // Removes card from back of vector hand
            cout << "The flipped card is the: " << flippedCard;
            string value = flippedCard.getValue();

            if (value == "Ace") { // +10 points for an Ace
                score += 10;
            } else if (value == "King" || value == "Queen" || value == "Jack") { // +5 points for a King, Queen, or Jack
                score += 5;
            } else if (value == "7") { // Divide score by 2 for 7
                score = score / 2;
            } else if (value == "2" || value == "3" || value == "4" || value == "5" || value == "6") { // Lose all points if 2, 3, 4, 5, 6
                score = 0;
            }
            // points for 8,9, and 10 are not listed as score doesn't change

            if (flippedCard.getSuit() == "Hearts") { // +1 to score for suit being a Hearts
                score += 1;
            }

            // Prints remaining cards in hand
            if(!hand.empty()) {
                cout << "The remaining unflipped cards are: " << endl;
                cout << "---------------------" << endl;
                // Prints current hand
                for (auto card : hand) {
                    cout << card;
                }
            } else {
                cout << "There are no cards left in the hand." << endl;
            }
            deck.replace(flippedCard); // Add flipped card to the bottom of the deck
        }
        else if (input == "n" || input == "N") { // breaks out of loop and prints Game Over message
            break;
        }
        else {
            cout << "Invalid input. Please type 'y' to flip a card or 'n' to end the game." << endl;
        }
    }
    cout << "Game over. Your final score is: " << score << endl;
}

// Deck constructor that initializes a full deck of 52 cards.
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

// Function to deal the top card from the deck.
Card Deck::deal() {
    if (head == nullptr) {
        throw runtime_error("Cannot deal from an empty deck.");
    }

    Node* oldHead = head;
    Card cardToDeal = head->val;
    head = head->next;
    delete oldHead;
    return cardToDeal;
}

// Function to place a card back at the bottom of the deck.
void Deck::replace(const Card& card) {
    Node* newCardNode = new Node(card);
    if (head == nullptr) {
        head = newCardNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newCardNode;
    }
}
// Destructor to clean up the linked list (deck of cards).
Deck::~Deck() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Overloading the << operator to print the deck's contents.
ostream & operator<<(ostream &out, const Deck &d){
    Node *curr = d.head;

    while(curr != nullptr){
        out << curr->val;
        curr = curr->next;
    }
    return out;
}

// Function to shuffle the deck of cards.
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