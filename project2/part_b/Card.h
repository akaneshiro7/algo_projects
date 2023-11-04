#pragma once
#include <string>
#include <iostream>
using namespace std;

// Declaration of the Card class.
class Card{
private:
    string value; // The value of the card, e.g., "Ace", "2", "3", etc.
    string suit;  // The suit of the card, e.g., "Clubs", "Diamonds", etc.

public:
    // Constructors and operator overloads
    Card();
    Card(const Card& copy);
    Card(string s, string v);
    Card& operator=(const Card& other);

    // Accessors
    string getSuit() const {return suit;}
    string getValue() const {return value;}

    // Mutators
    void setSuit(string s);
    void setValue(string v);

    // Friend function to overload << for printing Cards.
    friend ostream & operator<<(ostream &out, Card &c);
};
