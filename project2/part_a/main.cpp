/*
 * Flip Card game by Aidan Kaneshiro and Steven Lam
 * EECE2560
 * Part A
 * 11/3/23
 *
 *
 */
#include <iostream>
#include "Deck.h"

using namespace std;

int main() {
    Deck d = Deck(); // Create a deck of cards
    cout << d;       // Print the unshuffled deck
    cout << "---------------" << endl; // separator
    d.shuffle();     // Shuffle the deck
    cout << d;       // Print the shuffled deck
}
