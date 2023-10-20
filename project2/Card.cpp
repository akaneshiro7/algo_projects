#include <iostream>
#include <string>

#include "Card.h"

using namespace std;

Card::Card(){
    suit = "Clubs";
    value = "2";
}

Card::Card(std::string s, std::string v) : suit(s), value(v) {}


void Card::setSuit(string s) {
    suit = s;
}

void Card::setValue(string v) {
    value = v;
}

ostream & operator<<(ostream & out, Card &c) {
    out << c.value << " of " << c.suit << endl;
    return out;
}
