#pragma once
#include <string>
#include <iostream>
using namespace std;

// Class Card represents a playing card with a suit and a value
class Card{
private:
    string value; // The value of the card (e.g., "Ace", "2", "Queen")
    string suit; // The suit of the card (e.g., "Hearts", "Spades")
public:
    Card(); // Default constructor
    Card(string s, string v); // Parameterized constructor

    // Get methods for card's suit and value
    string getSuit() const {return suit;}
    string getValue() const {return value;}

    // Set methods for card's suit and value
    void setSuit(string s);
    void setValue(string v);

    // Friend function to enable direct cout function
    friend ostream & operator<<(ostream &out, Card &c);
};