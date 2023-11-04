/*
 * Flip Card game by Aidan Kaneshiro and Steven Lam
 * EECE2560
 * Part B
 * 11/3/23
 *
 *
 */
#include <iostream>
#include "Deck.h"

using namespace std;

// Main function to demonstrate shuffling and playing the card game.
int main() {
    Deck d = Deck();

    // Loop to shuffle the deck three times and print before and after each shuffle.
    for(int i = 1; i < 4; i++) {
        cout << "Deck before shuffle " << i << endl;
        cout << "------------------------" << endl;
        cout << d << endl;
        d.shuffle();
        cout << "Deck after shuffle " << i << endl;
        cout << "------------------------" << endl;
        cout << d << endl;
    }
    // Start the card-flipping game.
    playFlip(d);

}