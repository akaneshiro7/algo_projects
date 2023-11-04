#include <iostream>
#include <string>

#include "Card.h"

using namespace std;

// Default constructor sets the card to 2 of Clubs
Card::Card(){
    suit = "Clubs";
    value = "2";
}

// Parameterized constructor to initialize a card with a specific suit and value
Card::Card(std::string s, std::string v) : suit(s), value(v) {}

// Setter method to change the suit of the card
void Card::setSuit(string s) {
    suit = s;
}
// Setter method to change the value of the card
void Card::setValue(string v) {
    value = v;
}

// Overloaded output operator to print a card's value and suit
ostream & operator<<(ostream & out, Card &c) {
    out << c.value << " of " << c.suit << endl;
    return out;
}
