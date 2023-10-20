#include <iostream>
#include "Deck.h"

using namespace std;
int main() {
    Deck d = Deck();
    cout << d;
    d.shuffle();
    cout << d;
}