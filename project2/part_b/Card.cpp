#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

// Default constructor that initializes a Card as "2 of Clubs".
Card::Card(){
    suit = "Clubs";
    value = "2";
}

// Copy constructor that initializes a Card with the same values as another Card object.
Card::Card(const Card& cardCopy) {
    suit = cardCopy.getSuit();
    value = cardCopy.getValue();
}

// Constructor that initializes a Card with a given suit and value.
Card::Card(std::string s, std::string v) : suit(s), value(v) {}

// Assignment operator to copy the values from one Card to another.
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        value = other.value;
        suit = other.suit;
    }
    return *this;
}

// Setter for the Card's suit.
void Card::setSuit(string s) {
    suit = s;
}

// Setter for the Card's value.
void Card::setValue(string v) {
    value = v;
}

// Overloading the << operator to print a Card's details.
ostream & operator<<(ostream & out, Card &c) {
    out << c.value << " of " << c.suit << endl;
    return out;
}
