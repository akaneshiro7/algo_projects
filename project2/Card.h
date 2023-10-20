#pragma once
#include <string>
#include <iostream>
using namespace std;

class Card{
private:
    string value;
    string suit;
public:
    Card();
    Card(string s, string v);
    string getSuit() const {return suit;}
    string getValue() const {return value;}
    void setSuit(string s);
    void setValue(string v);
    friend ostream & operator<<(ostream &out, Card &c);
};